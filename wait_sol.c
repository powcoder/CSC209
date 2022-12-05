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
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char **argv) {
    // Declare any variables you need
    int result;
    int sum = 0;
    int status;

    // Write the code to loop over the command line arguments.
    // (Remember to skip the executable name.)
    for (int i = 1; i < argc; i++) {
        // call fork
        result = fork();
        if (result == -1) {   // case: a system call error
            // handle the error
            perror("fork");
            exit(1);
        } else if (result == 0) {  // case: a child process

            // child does their work here
            int len = strlen(argv[i]);
            exit(len);
        }
    }

    // Finish the code to sum up the return values from the children

    for (int i = 1; i < argc; i++) {
        if (wait(&status) == -1) {
            perror("wait");
            exit(1);
        }

        if (WIFEXITED(status)) {
            sum += WEXITSTATUS(status);
        }
    }

    printf("The length of all the args is %d\n",sum);
    return 0;
}
