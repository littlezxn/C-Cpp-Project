#include <iostream> //headerfile for Input/Output stream
using namespace std;
int main()
{
    int n, a = 0, b = 1, next;
    cout << "Enter number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++)
    {
        cout << a << " "; //first it prints a then it gives space and then next number;
        next = a + b;
        a = b;
        b = next;
    }
    cout << endl; //after ending the loop it will give a new line
    return 0;
}
//end of the program
/*
Example of 5
Enter number of terms: 5
Fibonacci Series: 0 1 1 2 3 
*/