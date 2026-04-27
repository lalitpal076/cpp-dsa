/*Concepts:
   Arguments in cpp
   1. Ordinary Variables | Value type variable (avilable in c &c++)
   2. Pointer Variables | Nullable type variable (avilable in c &c++)
   3. Reference Variables | Reference type variable (avilable only in c++)

   Reference Variable ?
   int x=5;      ordinary variable
   int* p = &x;  pointer variable (assignmet is optional)
   int &r = x;   reference variable (assignment is compulsory)
   reference variable can be only assigned by ordinary variable.
   And we can say r is the another name of x.
*/
#include <iostream>
using namespace std;

void fun(int x, int y){
    cout<<x<<"+"<<y<<"="<<x+y<<endl;
}

void fun1(int *p, int *q){
    cout<<*p<<"+"<<*q<<"="<<*p + *q<<endl;
}   

void fun2(int &a, int &b){
    cout<<a<<"+"<<b<<"="<<a + b<<endl;
}

int main() {
    int x = 5, y = 10;
    fun(x, y);        // Call by Value
    fun1(&x, &y);     // Call by Address
    fun2(x, y);       // Call by Reference
    return 0;
}