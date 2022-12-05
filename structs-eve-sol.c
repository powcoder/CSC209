https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#define MAX_AREA_SIZE 16
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct faculty {
    char *name;  
    char area[MAX_AREA_SIZE]; 
    int num_students; 
};

// We pass in a pointer because if we passed in the whole struct, we would
// get a copy of the struct and any changes made to the struct would be lost
// when the function returns.

void add_grad_student(struct faculty *member) {
    member->num_students++;
}


int main() {
    // Declare a struct faculty named p1.
    struct faculty p1;

    // Initialize p1 to represent Professor Roger Grosse, whose research area 
    // is ML (Machine Learning).  He is supervising 11 graduate students.

    // Use the dot notation when we have the struct.
    // We can set name to point to a string literal because it is type char *
    // We could also use malloc to dynamically allocate memory for name to point
    // to and then copy the string into that memory
    // We must copy a string in to area because it is type array of char

    p1.name = "Roger";
    strncpy(p1.area, "Machine Learning", MAX_AREA_SIZE);
    p1.area[MAX_AREA_SIZE - 1] = '\0';
    p1.students = 11;

    struct faculty *p2_pt;

	// allocate space for the faculty on the heap

    p2_pt = malloc(sizeof(struct faculty));

    // Set the values of *p2_pt to represent Professor Sheila McIlraith. 
    // Her research area is KR (Knowledge Representation).  
    // She is supervising 5 graduate students.

    // Use arrow notation when we have a pointer to a struct

    p2_pt->name = "Sheila";

    // IMPORTANT: be very careful that the 3rd argument to strncpy is the 
    // amount of space that has been allocated for the first argument.
   
    strncpy(p2_pt->area, "KR", MAX_AREA_SIZE);
    p2_p->students = 5;

    add_grad_student(&p1);
    add_grad_student(p2_pt);

	return 0;
}

