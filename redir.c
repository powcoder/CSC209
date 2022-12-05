https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char **argv) {
    // Expecting 2 arguments.  
    //    The first is a program to execute
    //    The second is the name of a file to redirect input from

    // open the file that is in argv[2]
    // Use "open" instead of "fopen" to get the file descriptor




    // Reset stdin so that it is coming from the open file




    // Use exec to run the program specified in argv[1]




    return 1;
}
