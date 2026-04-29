// Write a C program that dynamically allocates memory for a string entered by the user and finds its length using pointers.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *arr;

    arr = (char*)malloc(100 * sizeof(char));
    if(arr == NULL) {
        printf("Failed to allocate memory\n");
        return 0;
    }
    printf("Enter a string: ");
    scanf("%s", arr);

    char *start = arr;
    int length = 0;

    while(*(start + length) != '\0') {
        length++;
    }
    printf("Length of string is: %d\n", length);
    free(arr);
    
    return 0;
}