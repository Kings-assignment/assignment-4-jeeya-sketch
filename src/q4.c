// Write a C program that dynamically allocates memory for an integer array of size n, where n is entered by the user. Prompt the user to enter n elements and display them using pointers.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid size! Size must be positive.\n");
        return 1;
    }
    
    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input elements using pointers
    printf("Enter %d elements:\n", n);
    for (int *ptr = arr; ptr < arr + n; ptr++) {
        printf("Element %ld: ", ptr - arr + 1);
        scanf("%d", ptr);
    }
    
    // Display elements using pointers
    printf("\nArray elements are:\n");
    for (int *ptr = arr; ptr < arr + n; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");
    
    // Free the allocated memory
    free(arr);
    arr = NULL;
    
    return 0;
}