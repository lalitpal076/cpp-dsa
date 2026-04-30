/*  FUNCTION OVERLOADING 
    Multiple functions have the same name but with different parameters (different number of arguments, type, or order of arguments).
    
    The compiler decides which overloaded function to call at compile time based on:
        Number of arguments
        Type of arguments
        Order of arguments
    
    The compiler decides which function to bind at compile time using this priority rule:
        Exact Match
        Type Promotion
        Type Conversion
*/

#include <iostream>
using namespace std;

// these are the example of different number of arguments and exact match type overloading.
int add(int a, int b) {
    return a + b;
}
int add(int a, int b, int c) {
    return a + b + c;
}
double add(double a, double b) {
    return a + b;
}

// All function below have same name but different parameters.
// Area of rectangle 
int Area(int length, int width) {
    return length * width;
} 
// Area of square  
int Area(int side) {
    return side * side;
}
// Area of circle
double Area(double radius) {
    return 3.14 * radius * radius;
}
// Area of triangle
double Area(double base, double height) {
    return 0.5 * base * height;
}


// these are the example of type promotion and type conversion overloading.
// compiler promote 
// char to int, float to double, and bool to int when needed.

 
void display(int a) {
    cout << "Integer: " << a << endl;
}  
void display(double a) {
    cout << "Double: " << a << endl;
} 

int main() {
    char ch = 'A';
    float d = 3.14;
    int areofrect = Area(5, 10); 
    int areofsquare = Area(4); 
    double areofcircle = Area(2.5); 
    display(ch); // char promoted to int
    display(d); // float promoted to double
    return 0;
}