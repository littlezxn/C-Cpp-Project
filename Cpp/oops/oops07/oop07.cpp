/*
This program demonstrates the use of multiple inheritance in C++.
It defines a structure to hold user information and two classes: 
one for getting user information and another for checking the balance.
The final class inherits from both of these classes and combines their functionalities.
*/

#include "Include/header.h" // including header file

struct User *u; // global pointer to User structure

class User_info
{
public:
    void get_user_info()
    {
        u = new User; // dynamically allocating memory for User structure
        
        // taking user input for the User structure members
        std::cout << "Enter name: ";
        std::cin >> u->name;

        std::cout << "Enter age: ";
        std::cin >> u->age;

        std::cout << "Enter id: ";
        std::cin >> u->id;

        std::cout << "Enter Account no: ";
        std::cin >> u->Account_number;

        std::cout << "Enter Pin: ";
        std::cin >> u->pin;
        delete u;
    }
};

class Balance_checker
{
private:
    int cash;

public:
    Balance_checker(int b) { cash = b; };

    void Balance()
    {
        std::cout << "you have " << cash << " in your account." << std::endl;
    }
};

class Final : public User_info, public Balance_checker
{
public:
    Final(int Amount) : Balance_checker(Amount) {}

    void output()
    {
        get_user_info();
        Balance();
    }
};

int main()
{
    u = new User; // dynamically allocating memory for User structure
    Final F(10000);
    F.output();
    delete u; // deallocating memory for User structure
    return 0;
}
//end of code
//output:
/*
Enter name: kk
Enter age: 20
Enter id: 101
Enter Account no: 151141
Enter Pin: 1111
you have 10000 in your account.
*/