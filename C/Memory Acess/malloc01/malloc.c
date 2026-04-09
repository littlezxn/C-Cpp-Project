#include <stdio.h>  //Header file for input and output functions
#include <stdlib.h> //Header file for memory allocation functions
#include <string.h> //Header file for string manipulation functions

struct car
{
    int year;
    char Brand[50];
};
int main()
{
    // Dynamically allocate memory for an array of 2 struct car
    struct car *cars = (struct car *)malloc(2 * sizeof(struct car));

    // Check if memory allocation was successful
    if (cars == NULL)
    {
        printf("Error");
        return 1; // Exit with an error code
    }

    // Assign 1st values to the struct members
    strcpy(cars[0].Brand, "toyota");
    cars[0].year = 1990;

    // Assign 2nd values to the struct members
    strcpy(cars[1].Brand, "Ford");
    cars[1].year = 1991;

    // Print the values of the struct members
    for (int i = 0; i < 2; i++)
    {
        printf("%s - %d\n", cars[i].Brand, cars[i].year);
    }

    // Free the dynamically allocated memory
    free(cars);
    return 0;
}
// end of code
//  output
/*
toyota - 1990
Ford - 1991
*/