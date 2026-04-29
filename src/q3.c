// Write a C program that checks if a given string is a palindrome using pointers.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *start, char *end) {
    while (start < end) {
        // Skip non-alphanumeric characters
        while (start < end && !isalnum(*start)) {
            start++;
        }
        while (start < end && !isalnum(*end)) {
            end--;
        }
        
        // Compare characters (case-insensitive)
        if (tolower(*start) != tolower(*end)) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Is a palindrome
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    
    char *start = str;
    char *end = str + len - 1;
    
    if (isPalindrome(start, end)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }
    
    return 0;
}

