// Write a C program to read the contents of a text file and display them on the screen.
#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[50];
    char line[256];
    
    printf("Enter the filename to read: ");
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
    
    // Read and display file contents
    printf("\n=== Contents of '%s' ===\n\n", filename);
    
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    
    printf("\n=== End of File ===\n");
    
    // Close the file
    fclose(file);
    
    return 0;
}