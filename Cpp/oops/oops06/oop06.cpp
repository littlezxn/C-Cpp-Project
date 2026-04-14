/*
It is a program to demonstrate multilevel inheritance in C++. In this program
we have a base class "dog" with a member function "bark".
The "Cat" class inherits from the "dog" class and has its own member function "meow".
The "Cow" class inherits from the "Cat" class and has its own member function "moo".
Finally, the "Final" class inherits from the "Cow" class and has its own member function "display".
In the main function, we create an object of the "Final" class and call all the member functions to demonstrate multilevel inheritance.
*/
#include <iostream> //header file for input and output functions

class dog
{
public:
    void bark() // member function to print "Woof!"
    {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public dog
{
public:
    void meow() // member function to print "Meow!"
    {
        std::cout << "Meow!" << std::endl;
    }
};

class Cow : public Cat
{
public:
    void moo() // member function to print "Moo!"
    {
        std::cout << "Moo!" << std::endl;
    }
};

class Final : public Cow
{
public:
    void display() // member function to print "This is a final class."
    {
        std::cout << "This is a final class." << std::endl;
    }
};

int main()
{
    Final f;     // create an object of the final class
    f.bark();    // call the bark function from the dog class
    f.meow();    // call the meow function from the Cat class
    f.moo();     // call the moo function from the Cow class
    f.display(); // call the display function from the Final class
    return 0;
}
//end of the program
//output
/*
Woof!
Meow!
Moo!
This is a final class.
*/