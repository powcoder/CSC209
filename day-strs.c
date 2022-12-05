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
#include <string.h>
#include <unistd.h>

int main() {

    // Difference between strings and characters
    
    // Initializing the array s2 with a string that contains null termination character
    char s1[2] = "\0";  // 1

    // Trying to use a char to initialize an array => compiler error
    //char s2[2] = '\0';  // 2
    
    char s3[3] = "\\0"; // 3
    printf("%s\n", s3); // 4

    // static initialization
    char first[] = "Monday"; // {'M', 'o', 'n', ..}

    char *second = "Tuesday";

    char *third = malloc(strlen("Wednesday") + 1);
    strncpy(third, "Wednesday", strlen("Wednesday") + 1);

    //third = "Wednesday";  // third now points to string literal and is memory leak

    printf("%s ", first);
    sleep(1);
    printf("%s ", second);
    sleep(1);
    printf("%s\n", third);

    return 0;
}
