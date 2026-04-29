// Write a C program to create a file and write a user-entered string into it. Then display a 
// message confirming that the file has been written successfully.
#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[50];
    char content[500];
    
    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    
    // Remove newline character from filename
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }
    
    printf("Enter the string to write to the file: ");
    fgets(content, sizeof(content), stdin);
    
    // Open file in write mode
    file = fopen(filename, "w");
    
    // Check if file was created successfully
    if (file == NULL) {
        printf("Error: Could not create file '%s'\n", filename);
        return 1;
    }
    
    // Write the string to the file
    fprintf(file, "%s", content);
    
    // Close the file
    fclose(file);
    
    printf("\nFile '%s' has been written successfully!\n", filename);
    
    return 0;
}