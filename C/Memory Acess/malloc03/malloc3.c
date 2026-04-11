#include <stdio.h>  //header file for input and output functions
#include <stdlib.h> //header file for memory allocation functions
#include <string.h> //header file for string manipulation functions

struct employee
{
    int sallary;
    char name[20];
};

int main()
{
    struct employee *ptr = (struct employee *)malloc(3 * sizeof(struct employee)); // allocating memory for a struct employee

    if (ptr == NULL)
    {
        printf("Error");
        return 1; // exit with an error code
    }

    // assigning values to the struct members
    strcpy(ptr[0].name, "John");
    ptr[0].sallary = 55000;

    // assigning values to the struct members
    strcpy(ptr[1].name, "Doe");
    ptr[1].sallary = 60000;

    //assigning values to the struct members
    strcpy(ptr[2].name, "Smith");
    ptr[2].sallary = 70000;

    // printing the values of the struct members
    for (int i = 0; i < 3; i++)
    {
        printf("%s - %d\n", ptr[i].name, ptr[i].sallary);
    }

    free(ptr); // freeing the dynamically allocated memory
    return 0;
}
//end of code
// output
/*
John - 55000
Doe - 60000
Smith - 70000
*/