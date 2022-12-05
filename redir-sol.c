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
    int fd = open(argv[2], O_RDONLY);
    if(fd == -1) {
        perror("open");
        exit(1);
    }

    // Reset stdin so that it is coming from the open file

    int result = dup2(fd, fileno(stdin));
    if(result == -1) {
        perror("dup2");
        exit(1);
    }

    // Use exec to run the program specified in argv[1]
    execlp(argv[1], argv[1], NULL);
    perror("execlp");


    return 1;
}
