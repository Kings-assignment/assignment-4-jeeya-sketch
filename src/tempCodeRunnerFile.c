// Write a C program that defines a structure Book with members: title, author, and price. 
// Allow the user to enter details of n books and then display all books whose price is above a 
// user-defined value.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    float price;
} Book;

int main() {
    int n;
    float threshold;
    
    printf("Enter the number of books: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number of books!\n");
        return 1;
    }
    
    // Dynamically allocate memory for n books
    Book *books = (Book *)malloc(n * sizeof(Book));
    
    if (books == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Clear input buffer
    while (getchar() != '\n');
    
    // Input details for n books
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Book %d:\n", i + 1);
        
        printf("  Title: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        size_t len = strlen(books[i].title);
        if (len > 0 && books[i].title[len - 1] == '\n') {
            books[i].title[len - 1] = '\0';
        }
        
        printf("  Author: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        len = strlen(books[i].author);
        if (len > 0 && books[i].author[len - 1] == '\n') {
            books[i].author[len - 1] = '\0';
        }
        
        printf("  Price: ");
        scanf("%f", &books[i].price);
        
        // Clear input buffer
        while (getchar() != '\n');
    }
    
    // Get the threshold price
    printf("\nEnter the price threshold: ");
    scanf("%f", &threshold);
    
    // Display books with price above threshold
    printf("\n=== Books with Price Above %.2f ===\n", threshold);
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (books[i].price > threshold) {
            printf("\nBook %d:\n", ++count);
            printf("  Title: %s\n", books[i].title);
            printf("  Author: %s\n", books[i].author);
            printf("  Price: %.2f\n", books[i].price);
        }
    }
    
    if (count == 0) {
        printf("No books found with price above %.2f\n", threshold);
    }
    
    // Free the allocated memory
    free(books);
    books = NULL;
    
    return 0;
}
