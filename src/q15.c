// Write a C program that stores student records (name, roll number, and marks) into a 
// file and then reads and displays all stored records.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int rollNumber;
    float marks;
} Student;

void writeRecords(const char *filename) {
    FILE *file;
    int n;
    Student student;
    
    file = fopen(filename, "wb");
    
    if (file == NULL) {
        printf("Error: Could not create file '%s'\n", filename);
        return;
    }
    
    printf("How many student records do you want to enter? ");
    scanf("%d", &n);
    
    // Clear input buffer
    while (getchar() != '\n');
    
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        
        printf("  Name: ");
        fgets(student.name, sizeof(student.name), stdin);
        size_t len = strlen(student.name);
        if (len > 0 && student.name[len - 1] == '\n') {
            student.name[len - 1] = '\0';
        }
        
        printf("  Roll Number: ");
        scanf("%d", &student.rollNumber);
        
        printf("  Marks: ");
        scanf("%f", &student.marks);
        
        // Clear input buffer
        while (getchar() != '\n');
        
        // Write record to file
        fwrite(&student, sizeof(Student), 1, file);
    }
    
    fclose(file);
    printf("\nRecords have been saved to '%s' successfully!\n", filename);
}

void readRecords(const char *filename) {
    FILE *file;
    Student student;
    int count = 0;
    
    file = fopen(filename, "rb");
    
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }
    
    printf("\n=== Student Records ===\n\n");
    
    while (fread(&student, sizeof(Student), 1, file)) {
        count++;
        printf("Record %d:\n", count);
        printf("  Name: %s\n", student.name);
        printf("  Roll Number: %d\n", student.rollNumber);
        printf("  Marks: %.2f\n\n", student.marks);
    }
    
    if (count == 0) {
        printf("No records found in the file.\n");
    }
    
    fclose(file);
}

int main() {
    char filename[50];
    int choice;
    
    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    
    // Remove newline character from filename
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }
    
    while (1) {
        printf("\n=== Student Record Management ===\n");
        printf("1. Write new records to file\n");
        printf("2. Read records from file\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        // Clear input buffer
        while (getchar() != '\n');
        
        switch (choice) {
            case 1:
                writeRecords(filename);
                break;
            case 2:
                readRecords(filename);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}