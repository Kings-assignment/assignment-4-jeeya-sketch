// Write a C program that defines a structure Car with members: model, year, and mileage. 
// Store information for 3 cars and find the car with the lowest mileage.
#include <stdio.h>
#include <string.h>

#define NUM_CARS 3

typedef struct {
    char model[50];
    int year;
    float mileage;
} Car;

int main() {
    Car cars[NUM_CARS];
    int minIndex = 0;
    
    // Input details for 3 cars
    for (int i = 0; i < NUM_CARS; i++) {
        printf("Enter details for Car %d:\n", i + 1);
        
        printf("  Model: ");
        fgets(cars[i].model, sizeof(cars[i].model), stdin);
        // Remove newline character
        size_t len = strlen(cars[i].model);
        if (len > 0 && cars[i].model[len - 1] == '\n') {
            cars[i].model[len - 1] = '\0';
        }
        
        printf("  Year: ");
        scanf("%d", &cars[i].year);
        
        printf("  Mileage: ");
        scanf("%f", &cars[i].mileage);
        
        // Clear input buffer
        while (getchar() != '\n');
        
        printf("\n");
    }
    
    // Find car with lowest mileage
    for (int i = 1; i < NUM_CARS; i++) {
        if (cars[i].mileage < cars[minIndex].mileage) {
            minIndex = i;
        }
    }
    
    // Display car with lowest mileage
    printf("=== Car with Lowest Mileage ===\n");
    printf("Model: %s\n", cars[minIndex].model);
    printf("Year: %d\n", cars[minIndex].year);
    printf("Mileage: %.2f km\n", cars[minIndex].mileage);
    
    return 0;
}