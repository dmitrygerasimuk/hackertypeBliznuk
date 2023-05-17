<!-- GETTING STARTED -->
## Hacker Type for Bliznuk

This is a hackertype kinda program that outputs text as the keyboard is pressed. Check [https://hackertyper.net](https://hackertyper.net)

### Prerequisites

gcc

### Installation


1. Clone the repo
   ```sh
   git clone https://github.com/dmitrygerasimuk/hackertypeBliznuk
   ```
2. run make.sh
   ```sh
   chmod +x make.sh
   ./make.sh
   ```
 ### OR 

Just compile each file individually
```sh
gcc exploitCgi.c -o exploitCgi
./exploitCgi
```
 ```sh
gcc editScript.c -o editScript
./exploitCgi
```

```sh
gcc scanCgi.c -o scanCgi
./exploitCgi
```
 
## How it works

Each binary will output it's correspondint .txt to STDOUT, i.e. exploitCgi will print exploitCgi.txt and so on
 
   ```sh
   char c, *file = "exploitCgi.txt";
   ```
Note that exploitCgi reacts to DELIMITER char and DELAY char, see exploitCgi.txt for more info

   ```sh
    #define DELIMITER 0x12
    #define DELAYMETER 0x11
   ```

so when you press Enter it will output all chars before the Delimiter char which is defined as 0x12
and when it finds 0x11 it will delay for some random time, so it kinda mimics internet connection

<!-- USAGE EXAMPLES -->
## Usage

After compiling just run any of the binaries and start clicking keyboard
Try TAB and ENTER for different effects
 ```sh
  ./exploitCgi
  ./scanCgi
  ./editScript
   ```

There can be some sense in adding some fake command line arguments i.e.
```sh
./scanCgi interreklama.ru 
./editScript scanCgi.c
```
if it will be filmed somehow





<p align="right">(<a href="#readme-top">back to top</a>)</p>


