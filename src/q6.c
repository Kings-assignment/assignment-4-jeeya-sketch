// Write a C program that defines a structure called Student with members: name, roll number, 
// and marks. Prompt the user to enter data for one student and display the information.
#include <stdio.h>

typedef struct {
    char name[50];
    int rollNumber;
    float marks;
} Student;

int main() {
    Student student;
    
    printf("Enter student name: ");
    fgets(student.name, sizeof(student.name), stdin);
    
    printf("Enter roll number: ");
    scanf("%d", &student.rollNumber);
    
    printf("Enter marks: ");
    scanf("%f", &student.marks);
    
    printf("\n--- Student Information ---\n");
    printf("Name: %s", student.name);
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Marks: %.2f\n", student.marks);
    
    return 0;
}