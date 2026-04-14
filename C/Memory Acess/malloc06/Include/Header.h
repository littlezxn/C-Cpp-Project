#ifndef HEADER_H
#define HEADER_H

#include <stdio.h> //header file for input and output functions
#include <stdlib.h> //header file for memory allocation functions
#include <string.h> //header file for string manipulation functions

struct Data
{
	int age; // integer variable to store age
	char yname[20]; // character array to store name
	int pin; // integer variable to store pin
	int amount; // integer variable to store amount
};

void User_info(); //function prototype for User_info function

#endif // HEADER_H