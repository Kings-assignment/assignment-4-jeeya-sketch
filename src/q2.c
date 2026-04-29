// Write a C program that reverses an array of characters using pointers.
#include <stdio.h>

int main() 
{

    char arr[] = "James";

    char *start = arr;
    char *end = arr;
    int length = 0;
    int temp;

    while (*(start + length) != '\0') {
        length++;
        end++;
    }

    printf( "String is: %s\n", arr);

    for (int i = 0; i < length / 2; i++) {
        temp = *(start + i);
        *(start + i) = *(end - 1 - i);
        *(end - 1 - i) = temp;
    }

     printf( "Reversed string is: %s\n", arr);

    return 0;
}