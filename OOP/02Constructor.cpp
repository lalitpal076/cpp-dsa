 /*--- Assignment-10 ---*/
/*
1. Define a class Cuboid with length, breadth and height as instance member variables. Define constructors to initialise member variables.
2. Define a class Customer with instance members cust_id, name, email, mobile. Define non-parameterised constructor and parameterised constructor in the class.
3. Define a class Time with hr, min, sec as instance member variables. Define constructor to initialise Time object.

4. Define a class Complex with instance variables for real and imaginary part of a complex number. Define only one parameterised constructor in the class to initialise a complex object. Also define showData() method in the class to display object data.
Now create an array of Complex class with size 5 and display values of each object.

*/

 #include<iostream>
 #include<string.h>
 using namespace std;
 //Q1
 class Cuboid{
    int length, breadth, height;
    public:
        Cuboid(){
            length=0;
            breadth=0;
            height=0;
        }
        Cuboid(int x,int y,int z){
            length=x;
            breadth=y;
            height=z;
        }
 };
//Q2
 class Customer
 {
 private:
    int cust_id;
    char name[20];
    char email[25];
    char mobile[12];                                    
 public:
    Customer();
    Customer( int cust_id,char name[],char email[],char mobile[]);
    ~Customer();
 };
 
 Customer::Customer(/* args */)
 {
     cust_id=0;
     strcpy(name,"Note Available");
     strcpy(email,"example@gmail.com");
     strcpy(mobile,"+919876543210");
 }
 Customer::Customer( int cust_id,char name[],char email[],char mobile[])
 {
    this->cust_id=cust_id;
    strcpy(this->name,name);
    strcpy(this->email,email);
    strcpy(this->mobile,mobile);
 }

 //Q3
 class Time{
    int hr,min,sec;
    public:
        Time(int hr=00,int min=0, int sec=0){
            this->hr=hr;
            this->min=min;
            this->sec=sec;
        }

 };
 //Q4
 class Complex
 {
 private:
    int a,b;
 public:
    Complex(int x,int y);
    void showData();
 };
 
 Complex::Complex(int x,int y)
 {
    a=x;
    b=y;
 }
 void Complex::showData(){
    cout<<a<<"+"<<b<<"i"<<endl;
 }

 int main(){
    Complex c[5]={{1,2},{3,4},{5,6},{7,8},{9,1}};
    for(int i=0;i<5;i++){
        c[i].showData();
    }
 }
 