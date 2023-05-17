
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


int main() {

#define LOGO "[0;36mcGI-SCAN by [5mk|N[0m\n"

#define FOUNDSTR "[0;36m[FOUND][0m\n"
int i=0;
char *buff[100];
char *cginame[100];

  buff[1] = "GET /cgi-bin/unlg1.1 HTTP/1.0 ";
  buff[2] = "GET /cgi-bin/rwwwshell.pl HTTP/1.0 ";
  buff[3] = "GET /cgi-bin/phf HTTP/1.0 ";
  buff[4] = "GET /cgi-bin/Count.cgi HTTP/1.0 ";
  buff[5] = "GET /cgi-bin/test-cgi HTTP/1.0 ";
  buff[6] = "GET /cgi-bin/nph-test-cgi HTTP/1.0 ";
  buff[7] = "GET /cgi-bin/nph-publish HTTP/1.0 ";
  buff[8] = "GET /cgi-bin/php.cgi HTTP/1.0 ";
  buff[9] = "GET /cgi-bin/handler HTTP/1.0 ";
  buff[10] = "GET /cgi-bin/webgais HTTP/1.0 ";
  buff[11] = "GET /cgi-bin/websendmail HTTP/1.0 ";
  buff[12] = "GET /cgi-bin/webdist.cgi HTTP/1.0 ";
  buff[13] = "GET /cgi-bin/faxsurvey HTTP/1.0 ";
  buff[14] = "GET /cgi-bin/htmlscript HTTP/1.0 ";
  buff[15] = "GET /cgi-bin/pfdispaly.cgi HTTP/1.0 ";
  buff[16] = "GET /cgi-bin/perl.exe HTTP/1.0 ";
  buff[17] = "GET /cgi-bin/wwwboard.pl HTTP/1.0 ";
  buff[18] = "GET /cgi-bin/www-sql HTTP/1.0 ";
  buff[19] = "GET /cgi-bin/view-source HTTP/1.0 ";
  buff[20] = "GET /cgi-bin/campas HTTP/1.0 ";
  buff[21] = "GET /cgi-bin/aglimpse HTTP/1.0 ";
  buff[22] = "GET /cgi-bin/glimpse HTTP/1.0 ";
  buff[23] = "GET /cgi-bin/man.sh HTTP/1.0 ";
  buff[24] = "GET /cgi-bin/AT-admin.cgi HTTP/1.0 ";
  buff[25] = "GET /cgi-bin/filemail.pl HTTP/1.0 ";
  buff[26] = "GET /cgi-bin/maillist.pl HTTP/1.0 ";
  buff[27] = "GET /cgi-bin/jj HTTP/1.0 ";
  buff[28] = "GET /cgi-bin/info2www HTTP/1.0 ";
  buff[29] = "GET /cgi-bin/files.pl HTTP/1.0 ";
  buff[30] = "GET /cgi-bin/finger HTTP/1.0 ";
  buff[31] = "GET /cgi-bin/bnbform.cgi HTTP/1.0 ";
  buff[32] = "GET /cgi-bin/survey.cgi HTTP/1.0 ";
  buff[33] = "GET /cgi-bin/AnyForm2 HTTP/1.0 ";
  buff[34] = "GET /cgi-bin/textcounter.pl HTTP/1.0 ";
  buff[35] = "GET /cgi-bin/classifieds.cgi HTTP/1.0 ";
  buff[36] = "GET /cgi-bin/environ.cgi HTTP/1.0 ";
  buff[37] = "GET /cgi-bin/wrap HTTP/1.0 ";
  buff[38] = "GET /cgi-bin/cgiwrap HTTP/1.0 ";
  buff[39] = "GET /cgi-bin/guestbook.cgi HTTP/1.0 ";
  buff[40] = "GET /cgi-bin/edit.pl HTTP/1.0 ";
  buff[41] = "GET /cgi-bin/perlshop.cgi HTTP/1.0 ";
  buff[42] = "GET /_vti_inf.html HTTP/1.0 ";
  buff[43] = "GET /_vti_pvt/service.pwd HTTP/1.0 ";
  buff[44] = "GET /_vti_pvt/users.pwd HTTP/1.0 ";
  buff[45] = "GET /_vti_pvt/authors.pwd HTTP/1.0 ";
  buff[46] = "GET /_vti_pvt/administrators.pwd HTTP/1.0 ";
  buff[47] = "GET /_vti_bin/shtml.dll HTTP/1.0 ";
  buff[48] = "GET /_vti_bin/shtml.exe HTTP/1.0 ";
  buff[49] = "GET /cgi-dos/args.bat HTTP/1.0 ";
  buff[50] = "GET /cgi-win/uploader.exe HTTP/1.0 ";
  buff[51] = "GET /cgi-bin/rguest.exe HTTP/1.0 ";
  buff[52] = "GET /cgi-bin/wguest.exe HTTP/1.0 ";
  buff[53] = "GET /scripts/issadmin/bdir.htr HTTP/1.0 ";
  buff[54] = "GET /scripts/CGImail.exe HTTP/1.0 ";
  buff[55] = "GET /scripts/tools/newdsn.exe HTTP/1.0 ";
  buff[56] = "GET /scripts/fpcount.exe HTTP/1.0 ";
  buff[57] = "GET /cfdocs/expelval/openfile.cfm HTTP/1.0 ";
  buff[58] = "GET /cfdocs/expelval/exprcalc.cfm HTTP/1.0 ";
  buff[59] = "GET /cfdocs/expelval/displayopenedfile.cfm HTTP/1.0 ";
  buff[60] = "GET /cfdocs/expelval/sendmail.cfm HTTP/1.0 ";
  buff[61] = "GET /iissamples/exair/howitworks/codebrws.asp HTTP/1.0 ";
  buff[62] = "GET /iissamples/sdk/asp/docs/codebrws.asp HTTP/1.0 ";
  buff[63] = "GET /msads/Samples/SELECTOR/showcode.asp HTTP/1.0 ";
  buff[64] = "GET /search97.vts HTTP/1.0 ";
  buff[65] = "GET /carbo.dll HTTP/1.0 ";
  cginame[1] = "UnlG - backd00r ";
  cginame[2] = "THC - backd00r  ";
  cginame[3] = "phf..classic :) ";
  cginame[4] = "Count.cgi       ";
  cginame[5] = "test-cgi        ";
  cginame[6] = "nph-test-cgi    ";
  cginame[7] = "nph-publish     ";
  cginame[8] = "php.cgi         ";
  cginame[9] = "handler         ";
  cginame[10] = "webgais         ";
  cginame[11] = "websendmail     ";
  cginame[12] = "webdist.cgi     ";
  cginame[13] = "faxsurvey       ";
  cginame[14] = "htmlscript      ";
  cginame[15] = "pfdisplay       ";
  cginame[16] = "perl.exe        ";
  cginame[17] = "wwwboard.pl     ";
  cginame[18] = "www-sql         ";
  cginame[19] = "view-source     ";
  cginame[20] = "campas          ";
  cginame[21] = "aglimpse        ";
  cginame[22] = "glimpse         ";
  cginame[23] = "man.sh          ";
  cginame[24] = "AT-admin.cgi    ";
  cginame[25] = "filemail.pl     ";
  cginame[26] = "maillist.pl     ";
  cginame[27] = "jj              ";
  cginame[28] = "info2www        ";
  cginame[29] = "files.pl        ";
  cginame[30] = "finger          ";
  cginame[31] = "bnbform.cgi     ";
  cginame[32] = "survey.cgi      ";
  cginame[33] = "AnyForm2        ";
  cginame[34] = "textcounter.pl  ";
  cginame[35] = "classifields.cgi";
  cginame[36] = "environ.cgi     ";
  cginame[37] = "wrap            ";
  cginame[38] = "cgiwrap         ";
  cginame[39] = "guestbook.cgi   ";
  cginame[40] = "edit.pl         ";
  cginame[41] = "perlshop.cgi    ";
  cginame[42] = "_vti_inf.html   ";
  cginame[43] = "service.pwd     ";
  cginame[44] = "users.pwd       ";
  cginame[45] = "authors.pwd     ";
  cginame[46] = "administrators  ";
  cginame[47] = "shtml.dll       ";
  cginame[48] = "shtml.exe       ";
  cginame[49] = "args.bat        ";
  cginame[50] = "uploader.exe    ";
  cginame[51] = "rguest.exe      ";
  cginame[52] = "wguest.exe      ";
  cginame[53] = "bdir - samples  ";
  cginame[54] = "CGImail.exe     ";
  cginame[55] = "newdsn.exe      ";
  cginame[56] = "fpcount.exe     ";
  cginame[57] = "openfile.cfm    ";
  cginame[58] = "exprcalc.cfm    ";
  cginame[59] = "dispopenedfile  ";
  cginame[60] = "sendmail.cfm    ";
  cginame[61] = "codebrws.asp    ";
  cginame[62] = "codebrws.asp 2  ";
  cginame[63] = "showcode.asp    ";
  cginame[64] = "search97.vts    ";
  cginame[65] = "carbo.dll       ";



 //printf(LOGO);
 fprintf(stderr,LOGO);
for (i=1; i< 64; i++)
{ 

   printf("\r");
  
    printf("Searching for %s ", cginame[i]);
    printf("%-50s",buff[i]);
      fflush(stdout);
      if ( rand() % 5 > 1) { usleep(10000+( rand() % 400000) );} 
      usleep(500000);

 	if (rand() % 64 > 59) { printf(FOUNDSTR); }


    
}
  return 0;

}
