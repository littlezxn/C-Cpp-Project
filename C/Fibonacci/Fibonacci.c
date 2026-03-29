#include<stdio.h>
int main(){
    int n, a = 0, b = 1, next;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a); //first it prints a then it gives space and then next number;
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n"); //after ending the loop it will give a new line
    return 0;
}
//end of the program
/*Example of 5
Enter number of terms: 5
Fibonacci Series: 0 1 1 2 3 
*/