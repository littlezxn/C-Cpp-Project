#include <iostream>
using namespace std;
int main()
{
    int n, a = 0, b = 1, next;
    cout << "Enter number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++)
    {
        cout << a << " ";
        next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
    return 0;
}