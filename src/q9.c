// Write a C program that uses a structure Point with members x and y, representing coordinates. 
// Write a function that takes two Point structures and returns the distance between them.

#include <stdio.h>
#include <math.h>

typedef struct{
    double x;
    double y;   
} Point;

double distance(Point p1, Point p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    Point p1, p2;

    printf("Enter coordinates of first point (x y): ");
    scanf("%lf %lf", &p1.x, &p1.y);

    printf("Enter coordinates of second point (x y): ");
    scanf("%lf %lf", &p2.x, &p2.y);

    double dist = distance(p1, p2);
    printf("Distance between points: %.2lf\n", dist);

    return 0;
}