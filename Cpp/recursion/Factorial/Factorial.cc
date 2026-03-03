#include <iostream>
using namespace std;
int factorial(int i)
{
    if (i == 1 || i == 0)
    {
        return 1;
    }
    return i * factorial(i - 1);
}

int main()
{
    int i, c;
    std::cout << "Enter the number: ";
    std::cin >> i;
    c = factorial(i);
    std::cout << c << std::endl;
    return 0;
}