//Brody Reiter UCFNID: br848146
#include <stdio.h>
#include <math.h>

#define PI 3.14159

// Helper function to get user input and calculate distance, while caching the results
double calculateDistance() {
    static int isCalculated = 0;  // Static flag to ensure input is only requested once
    static double x1, y1, x2, y2, distance;  // Static variables to cache coordinates and distance

    if (!isCalculated) {
        // Get user input for the first and second points
        printf("Enter the coordinates of the first point (x1, x2):\n");
        printf("x1: ");
        scanf("%lf", &x1);
        printf("x2: ");
        scanf("%lf", &x2);

        printf("Enter the coordinates of the second point (y1, y2):\n");
        printf("y1: ");
        scanf("%lf", &y1);
        printf("y2: ");
        scanf("%lf", &y2);

        // Calculate the distance between the two points
        distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        // Print distance message
        printf("The distance between the two points is %.2f\n", distance);
        
        // Set the flag to indicate that the points have been inputted and the distance calculated
        isCalculated = 1;
    }
    // print points entered repeatedly
    printf("Point #1 entered: x1 = %.2f; y1 = %.2f\n", x1, y1);
    printf("Point #2 entered: x2 = %.2f; y2 = %.2f\n", x2, y2);
    
    // Return the cached distance
    return distance;
}

// Function to calculate perimeter of the circle (city)
double calculatePerimeter() {
    double distance = calculateDistance();  // Use the cached distance
    double perimeter = 2 * PI * (distance / 2);
    printf("The perimeter of the city encompassed by your request is %.2f\n", perimeter);
    return 1.0; 
}

// Function to calculate area of the circle (city)
double calculateArea() {
    double distance = calculateDistance();  // Use the cached distance
    double radius = distance / 2;
    double area = PI * pow(radius, 2);
    printf("The area of the city encompassed by your request is %.2f\n", area);
    return 1.0; 
}

// Function to calculate width (diameter) of the circle
double calculateWidth() {
    double distance = calculateDistance();  // Use the cached distance
    printf("The width of the city encompassed by your request is %.2f\n", distance);
    return 1.0;  
}

// Function to calculate height (diameter) of the circle
double calculateHeight() {
    double distance = calculateDistance();  // Use the cached distance
    printf("The height of the city encompassed by your request is %.2f\n", distance);
    return 1.0;  
}

int main(int argc, char **argv) {
    // Call each function to perform calculations
    calculatePerimeter();
    calculateArea();
    calculateWidth();
    calculateHeight();

    return 0;  // Return 0 for autograder
}

