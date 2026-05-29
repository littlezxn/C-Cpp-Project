#include<iostream> //Header file for input and output stream
int main(){
    int a[5] = {10,20,30,40,50}; //Declaration and initialization of an array of integers
    for (int i = 0; i < 5; i++) //Loop to iterate through the array and print its elements
    {
        std::cout<<a[i]<<" ";
    }
    return 0;
}
//end of code
//output: 10 20 30 40 50