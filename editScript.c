//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <signal.h>

#define N 1
#define DELIMITER 0x0a 
#define DELAYMETER 0x11
#define ENTERKEY 10
#define ESCKEY 27 


struct termios tty_attr_old;

void tty_raw() {
  struct termios tty_attr;

  tcgetattr(0, &tty_attr);

  tty_attr.c_lflag &= (~(ICANON | ECHO));
//  tty_attr.c_cc[CTIME] = 0;
  tty_attr.c_cc[VMIN] = 1;

  tcsetattr(0, TCSANOW, &tty_attr);
}

void ff() {
  tcsetattr(0, TCSANOW, &tty_attr_old);
  putchar('\n');
  exit(0);
}

void print_next_bit(int fd) {
  char buf[N + 1];
  int n;
  
  memset(buf, 0, N);
  
  if ((n = read(fd, buf, N)) > 0) {
    write(1, buf, n);
    memset(buf, 0, N);
  }
}


void print_until_delimiter(int fd) {
  char buf[N + 1];
  int n;
  

  pr:
    memset(buf, 0, N);
  if ((n = read(fd, buf, N)) > 0) {
    if  ( buf[0] != DELAYMETER  ) { sleep(0);} 
     else 
            { usleep(50000 + ( rand() % 1000000)); } 
   if  (buf[0] != DELAYMETER )   write(1, buf, n);
  if ( rand() % 5 > 3 ) usleep(rand() % 500); 
   if ( buf[0] != DELIMITER ) goto pr; 
  }

}


void print_stuff_bit(char stuff) {
  char buf[N + 1];
  int n;
  char *s=malloc(10);
  n=2;
  s="\n";
  memset(buf, 0, N);
    
  
    write(1, s, n);
    memset(buf, 0, N);
 
}

int main(int argc, char **argv) {
  // char c, *file = "/root/CGI_tools/var/dict.txt"; 
  
   char c, *file = "editScript.txt";

  int fd;
  if (argc > 1)
    file = argv[1];

system("clear");
  
tcgetattr(0, &tty_attr_old);
  tty_raw();

  signal(SIGINT, &ff);
  fd = open(file, O_RDONLY);
  if (fd <= 0) {
    perror("open()");
    ff();
  }

  while (read(0, &c, 1)) {
    if (c == ESCKEY)
      ff();
    else if  (c == ENTERKEY)
      {
       print_until_delimiter(fd);
      }
    else
      print_next_bit(fd);
       
  }
  tcsetattr(0, TCSANOW, &tty_attr_old);
  
  close(fd);
  return 0;
}
