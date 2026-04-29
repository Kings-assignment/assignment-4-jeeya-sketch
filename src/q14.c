// Write a C program that counts the number of characters, words, and lines in a text file.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[50];
    int characters = 0, words = 0, lines = 0;
    char ch;
    int inWord = 0;
    
    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    
    // Remove newline character from filename
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }
    
    // Open file in read mode
    file = fopen(filename, "r");
    
    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }
    
    // Read and count
    while ((ch = fgetc(file)) != EOF) {
        characters++;
        
        // Count lines
        if (ch == '\n') {
            lines++;
        }
        
        // Count words
        if (isspace(ch)) {
            if (inWord) {
                words++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }
    
    // Handle last word if file doesn't end with whitespace
    if (inWord) {
        words++;
    }
    
    // If file has content but no newline at end, count it as a line
    if (characters > 0) {
        if (ch != '\n') {
            lines++;
        }
    }
    
    // Close the file
    fclose(file);
    
    // Display results
    printf("\n=== File Statistics ===\n");
    printf("File name: %s\n", filename);
    printf("Number of characters: %d\n", characters);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);
    
    return 0;
}