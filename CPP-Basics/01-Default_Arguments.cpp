#include <iostream>
using namespace std;
/*Concepts:
  If no argument is passed, then the default value will be used.
  If an argument is passed, then the default value will be overridden.

  Rules:
  1. must be assigned from right to left.
    ex: void fun(int a, int b = 10, int c = 20); // valid
        void fun(int a = 10, int b, int c = 20); // invalid
  2. Default arguments can be used in function declaration or definition, but not in both.
*/

void student(string name = "Unknown", int age = 18) {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "--------" << endl;
}

void sumOfThreeNumbers(int a = 0, int b = 0, int c = 0) {
    int sum = a + b + c;
    cout << "Sum: " << sum << endl;
}

int main() {
    student();                  // Default values
    student("Lalit");           
    student("Rahul", 22);
    sumOfThreeNumbers();        // Default values get used
    sumOfThreeNumbers(5);       //b and c will take default value
    sumOfThreeNumbers(5, 10); 
    sumOfThreeNumbers(5, 10, 15); 

    return 0;
}