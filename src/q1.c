// Write a C program that swaps the values of two integers using pointers.

#include <stdio.h>

void swap_using_pointer(int *x, int *y)
{
    int temp;
    temp = *x; 
    *x = *y;   
    *y = temp; 

}

int main() 
{
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Numbers before swaping: num1 = %d, num2 = %d\n", num1, num2);

    swap_using_pointer(&num1, &num2);

    printf("Numbers after swaping: num1 = %d, num2 = %d\n", num1, num2);


    return 0;
}