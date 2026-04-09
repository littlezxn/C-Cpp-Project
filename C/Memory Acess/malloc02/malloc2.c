#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *ptr;
    ptr = (char *)malloc(15 * sizeof(char));
    if(ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        strcpy(ptr, "Hello World");
        printf("String = %s\n", ptr);
    }
    free(ptr);
    return 0;
}
// end of code
// output
/*
String = Hello World
*/