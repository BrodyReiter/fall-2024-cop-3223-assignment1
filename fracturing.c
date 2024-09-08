//Brody Reiter UCFNID: br848146
#include <stdio.h>
#include <math.h>

#define PI 3.14159

// Function to ask for user input for a single coordinate
double askForUserInput() {
    double value;
    scanf("%lf", &value);
    return value;
}

// Function to get user input for two points
void getUserInput(double *x1, double *y1, double *x2, double *y2) {
    printf("Enter the coordinates of the first point (x1, y1):\n");
    printf("x1: ");
    *x1 = askForUserInput();
    printf("y1: ");
    *y1 = askForUserInput();

    printf("Enter the coordinates of the second point (x2, y2):\n");
    printf("x2: ");
    *x2 = askForUserInput();
    printf("y2: ");
    *y2 = askForUserInput();
}

// Function to calculate distance between two points
double calculateDistance() {
    double x1, y1, x2, y2;
    getUserInput(&x1, &y1, &x2, &y2);
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Print points and distance
    printf("Point #1 entered: x1 = %.2f; y1 = %.2f\n", x1, y1);
    printf("Point #2 entered: x2 = %.2f; y2 = %.2f\n", x2, y2);
    printf("The distance between the two points is %.2f\n", distance);

    return distance; // Return the calculated distance
}

// Helper function to avoid recalculating distance multiple times
double getCachedDistance() {
    static double cachedDistance = -1.0;
    if (cachedDistance < 0) {
        cachedDistance = calculateDistance();
    }
    return cachedDistance;
}

// Function to calculate perimeter of the circle (city)
double calculatePerimeter() {
    double distance = getCachedDistance(); // Use cached distance
    double perimeter = 2 * PI * (distance / 2);
    printf("The perimeter of the city encompassed by your request is %.2f\n", perimeter);
    return 3.0;  // Return a difficulty rating (1.0 - 5.0)
}

// Function to calculate area of the circle (city)
double calculateArea() {
    double distance = getCachedDistance(); // Use cached distance
    double radius = distance / 2;
    double area = PI * pow(radius, 2);
    printf("The area of the city encompassed by your request is %.2f\n", area);
    return 4.0;  // Return a difficulty rating (1.0 - 5.0)
}

// Function to calculate width (diameter) of the circle
double calculateWidth() {
    double distance = getCachedDistance(); // Use cached distance
    printf("The width of the city encompassed by your request is %.2f\n", distance);
    return 2.0;  // Return a difficulty rating (1.0 - 5.0)
}

// Function to calculate height (diameter) of the circle
double calculateHeight() {
    double distance = getCachedDistance(); // Use cached distance
    printf("The height of the city encompassed by your request is %.2f\n", distance);
    return 2.0;  // Return a difficulty rating (1.0 - 5.0)
}

int main(int argc, char **argv) {
    // Call each function to perform calculations
    calculatePerimeter();
    calculateArea();
    calculateWidth();
    calculateHeight();

    return 0; // Return 0 for autograder
}
