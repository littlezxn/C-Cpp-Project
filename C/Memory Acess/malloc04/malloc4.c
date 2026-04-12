#include <stdio.h>  //header file for input and output functions
#include <stdlib.h> //header file for memory allocation functions
#include <string.h> //header file for string manipulation functions

struct School
{
    int rollno;
    char name[20];
    int marks;
};

int main()
{
    // Dynamically allocate memory for an array of 3 struct School
    struct School *student = (struct School *)malloc(3 * sizeof(struct School));

    // Check if memory allocation was successful
    if (student == NULL)
    {
        printf("Error");
        return 1;
    }

    // Assign values to the struct members
    strcpy(student[0].name, "Rahul");
    student[0].rollno = 101;
    student[0].marks = 450;

    // Assign values to the struct members
    strcpy(student[1].name, "Rohit");
    student[1].rollno = 102;
    student[1].marks = 400;

    // Assign values to the struct members
    strcpy(student[2].name, "Mohar");
    student[2].rollno = 103;
    student[2].marks = 300;
    // Print the values of the struct members

    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s\nRoll No: %d\nMarks out of 500: %d\n", student[i].name, student[i].rollno, student[i].marks);
    }

    // Free the dynamically allocated memory
    free(student);
    return 0;
}
// end of the program
// output
/*
Name: Rahul
Roll No: 101
Marks out of 500: 450
Name: Rohit
Roll No: 102
Marks out of 500: 400
Name: Mohar
Roll No: 103
Marks out of 500: 300
*/