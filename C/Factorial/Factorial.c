#include<stdio.h> //headerfile for input and output
int Factorial(int n){
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return n * Factorial(n - 1);
    }   
}
int main(){
    int x;
    printf("Enter the number you want the factorial of: ");
    scanf("%d", &x);
    x = Factorial(x);
    printf("%d", x);
    return 0;
}
//end of the program
// output
/*
Enter the number you want the factorial of: 5
120
*/

//how it works
/*
/*
factorial of 5 will be
5 * Factorial(4)
5 * 4 * Factorial(3)
5 * 4 * 3 * Factorial(2)
5 * 4 * 3 * 2 * Factorial(1)
5 * 4 * 3 * 2 * 1 * Factorial(0)
5 * 4 * 3 * 2 * 1 * 1
120
*/