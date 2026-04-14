#include "Include/Header.h"

// function definition for User_info function
void User_info()
{
	// pointer to struct Data
	struct Data *d;
	// dynamically allocate memory for struct Data
	d = (struct Data *)malloc(sizeof(struct Data));
	// check if memory allocation was successful
	if (d == 0)
	{
		printf("Error");
		return;
	}

	// assign values to the struct members
	printf("Enter your name: ");
	scanf("%s", &d->yname);

	// assign values to the struct members
	printf("Enter Your age: ");
	scanf("%d", &d->age);

	// assign values to the struct members
	printf("Enter Your pin: ");
	scanf("%d", &d->pin);

	// assign values to the struct members
	d->amount = 100000;

	// print the values of the struct members
	printf("---------------------------------------\n");
	printf("Name: %s\n", d->yname);
	printf("Age: %d\n", d->age);
	printf("Total amount: %d\n", d->amount);
	printf("----------------------------------------\n");

	// free the dynamically allocated memory
	free(d);
}

// main function
int main()
{
	// call the User_info function
	User_info();
	return 0;
}
// End of the program
// output
/*
Enter your name: Jonh
Enter Your age: 25
Enter Your pin: 1234
---------------------------------------
Name: Jonh
Age: 25
Total amount: 100000
----------------------------------------
*/