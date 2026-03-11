#include <stdio.h> // Header file for input and output

int main(void) {
    int x;
    for (;;) {
        printf("Enter the number for the table (0 or non-number to exit): ");
        if (scanf("%d", &x) != 1) {
            break; // non-number entered
        }
        if (x == 0) {
            break;
        }
        for (int i = 1; i <= 10; i++) {
            printf("%d x %d = %d\n", x, i, x * i);
        }
    }
    return 0;
}
//end of the program
//output
/*
Enter the number for the table (0 or non-number to exit): 2
2 x 1 = 2
2 x 2 = 4
2 x 3 = 6
2 x 4 = 8
2 x 5 = 10
2 x 6 = 12
2 x 7 = 14
2 x 8 = 16
2 x 9 = 18
2 x 10 = 20
*/