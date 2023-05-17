<!-- GETTING STARTED -->
## Hacker Type for Bliznuk

This is a hackertype kinda program that outputs text as the keyboard is pressed. Check [https://hackertyper.net](https://hackertyper.net)

### Prerequisites

gcc

### Installation

_Below is an example of how you can instruct your audience on installing and setting up your app. This template doesn't rely on any external dependencies or services._

2. Clone the repo
   ```sh
   git clone 
   ```
3. run make.sh
   ```sh
   chmod +x make.sh
   ```
<!-- USAGE EXAMPLES -->

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



<p align="right">(<a href="#readme-top">back to top</a>)</p>


<p align="right">(<a href="#readme-top">back to top</a>)</p>


