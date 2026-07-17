#include <stdio.h> //for printf() and scanf() functions
#include <stdlib.h> //for system() function

void displayMenu();
void choices();

int main()
{
    displayMenu();
    choices();
    return 0;
}
void displayMenu()
{
    printf("Welcome to C/C++ programming!\n");
    printf("\n");
    printf("Which language you want to learn?\n");
    printf("1 for C\n2 for C++\n");
}
void choices()
{
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("You have chosen to learn C programming.\n");
        system("cd C && ls || dir");
        break;
    case 2:
        printf("You have chosen to learn C++ programming.\n");
        system("cd Cpp && ls || dir");
        break;
    default:
        printf("Invalid choice.\n");
    }
}