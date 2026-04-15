#include <stdio.h>  //header file for input and output functions
#include <stdlib.h> //header file for memory allocation functions
#include <string.h> //header file for string manipulation functions
struct school
{
    int rollno;    // integer variable to store roll number
    char name[20]; // character array to store name
};

struct school_name
{
    char name[20]; // character array to store school name
};

int main()
{
    struct school *s; // pointer to struct school

    struct school_name *sn; // pointer to struct school_name

    s = (struct school *)malloc(sizeof(struct school)); // dynamically allocate memory for struct school

    sn = (struct school_name *)malloc(sizeof(struct school_name)); // dynamically allocate memory for struct school_name

    // check if memory allocation was successful
    if (s == 0 || sn == 0)
    {
        printf("Error");
        return 1;
    }

    // assign values to the struct members
    s->rollno = 101;

    // assign values to the struct members
    strcpy(s->name, "Jonh");
    strcpy(sn->name, "ARCH School");

    // print the values of the struct members
    printf("Student name is %s\n", s->name);
    printf("Roll no is %d\n", s->rollno);
    printf("School name is %s\n", sn->name);

    // free the dynamically allocated memory
    free(s);
    free(sn);

    return 0;
}
// End of the program
// output
/*
Student name is Jonh
Roll no is 101
School name is ARCH School
*/
