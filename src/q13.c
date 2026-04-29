// Write a C program that copies the contents of one file to another file.
#include <stdio.h>
int main()
{
    
    char sourceFile[100], destination_file[100];
    FILE *source, *destination;
    char ch;

    printf("Enter source file name: ");
    scanf("%s", sourceFile);

    printf("Enter destination file name: ");
    scanf("%s", destination_file);

    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Could not open source file.\n");
        return 0;
    }

    destination = fopen(destination_file, "w");
    if (destination == NULL) {
        printf("Could not open destination file.\n");
        fclose(source);
        return 0;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File copied successfully.\n");

    fclose(source);
    fclose(destination);

    return 0;
}