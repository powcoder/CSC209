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

/*
Write a program that takes at least one command-line argument, where 
each argument is the name of an executable to run.

The program should fork a new child for each command-line argument, and the 
child should call exec to run the executable named by the argument. (The 
executable itself takes no arguments.) The child should exit with a non-zero 
value if the exec fails.

The parent process should wait for all of its child processes to complete.
If all of its child processes exit successfully with an exit status of 0, 
the parent prints "Success\n".  Otherwise, the parent prints "Failure\n".

Here is an example of how the program could be called:
./run_all ls date ps
*/

/* What if we wanted to run each one in sequence? */

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (fork() == 0) {
            // Child process: run an executable.
            // First argument is the name of the file to be executed
            // Remaining arguments are what gets set into argv for main
            execl(argv[i], argv[i], NULL);

            /* 
            // Another way to call exec, using an array (vector) of arguments
            char *args[2];
            args[0] = argv[i]; // 0th element is the name of the program
            args[1] = NULL;

            // First argument is the name of the file to be executed
            execvp(argv[i], args);
            */

            perror("exec");
            exit(1);
        }
    }


    // Parent here.
    int status;
    int all_success = 1;
    for (int i = 1; i < argc; i++) {
        // This is not a good way to call wait, unless all
        // we care about is making sure the parent doesn't 
        // exit before its children
        wait(&status);
    }

    if (all_success) {
        printf("Success\n");
    } else {
        printf("Failure\n");
    }

    return 0;
}
