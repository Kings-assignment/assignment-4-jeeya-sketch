// Write a C program that defines a structure Employee with members: name, employee ID, and salary. 
// Take input for 5 employees and display the details of the employee with the highest salary.
#include <stdio.h>
#include <string.h>

#define NUM_EMPLOYEES 5

typedef struct {
    char name[50];
    int employeeID;
    float salary;
} Employee;

int main() {
    Employee employees[NUM_EMPLOYEES];
    int maxIndex = 0;
    
    // Input details for 5 employees
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        
        printf("  Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        // Remove newline character
        size_t len = strlen(employees[i].name);
        if (len > 0 && employees[i].name[len - 1] == '\n') {
            employees[i].name[len - 1] = '\0';
        }
        
        printf("  Employee ID: ");
        scanf("%d", &employees[i].employeeID);
        
        printf("  Salary: ");
        scanf("%f", &employees[i].salary);
        
        // Clear input buffer
        while (getchar() != '\n');
        
        printf("\n");
    }
    
    // Find employee with highest salary
    for (int i = 1; i < NUM_EMPLOYEES; i++) {
        if (employees[i].salary > employees[maxIndex].salary) {
            maxIndex = i;
        }
    }
    
    // Display employee with highest salary
    printf("=== Employee with Highest Salary ===\n");
    printf("Name: %s\n", employees[maxIndex].name);
    printf("Employee ID: %d\n", employees[maxIndex].employeeID);
    printf("Salary: %.2f\n", employees[maxIndex].salary);
    
    return 0;
}