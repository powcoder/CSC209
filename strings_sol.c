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


// Part 3: Implement build_month_list.
char **build_month_list() {

    char **month_list = malloc(3 * sizeof(char *));

    month_list[0] = malloc((strlen("January") + 1) * sizeof(char));
    strcpy(month_list[0], "January");

    month_list[1] = malloc((strlen("February") + 1) * sizeof(char));
    strcpy(month_list[1], "February");

    month_list[2] = malloc((strlen("March") + 1) * sizeof(char));
    strcpy(month_list[2], "March");

    return month_list;
}

int main() {

    // Part 1: Declare and initialize first, second, and third.
    char first[7] = "Monday";
    char *second = "Tuesday";
    char *third = malloc(10 * sizeof(char));
      // make sure you understand why this commented-out line is incorrect
      // Variable third is a assigned a pointer to a block of size 10 * char on the heap.
      // The code below would then point third at the string literal "Wednesday",
      // which leaves the block of memory malloc'd with no reference to it (a memory leak).
      //third = "Wednesday"; 
    strcpy(third,"Wednesday");

    printf("%s %s %s\n", first, second, third);

    // Part 2: Declare and initialize string_list.
    char *string_list[3];
    string_list[0] = first;
    string_list[1] = second;
    string_list[2] = third;

    printf("%s %s %s\n", string_list[0], string_list[1], string_list[2]);

    // For part 3: Once you've implemented build_month_list, uncomment this code.
    char **months = build_month_list();
    for(int i = 0; i < 3; i++) {
        printf("%s ", months[i]);
    }
    printf("\n");

    for(int i = 0; i < 3; i++) {
        months[i][3] = '\0';
        printf("%s ", months[i]);
    }
    printf("\n");

    return 0;
}
