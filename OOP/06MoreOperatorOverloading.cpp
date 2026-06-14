/*  ----- Operator Overloading ------*/

/*
1. Define a class Complex and provide a unary friend operator - to negate the real and imaginary part of a complex number.
2. Define a class Integer with instance variable of type int. Provide a friend logical operator not !. Also define a friend operator == to compare two Integer objects.
3. Create a Coordinate class with 2 instance variables x and y. Overload comma operator such that when you write c3 = (c1 , c2) then c2 is assigned to c3. Where c1, c2, and c3 are objects of Coordinate class.
4. In Question-3, provide overloaded insertion and extraction operators.
5. Define a class Student with roll no, name and age as instance variables. Create setStudent() and showStudent() methods in the class. Overload operator == to compare two Student objects.
*/

#include<iostream>
#include<string.h>
using namespace std;

//Q1
class Complex
{
private:
    int real,imag;
public:
    friend Complex& operator-(Complex &);
};

Complex& operator-(Complex &obj){
    obj.real=-obj.real;
    obj.imag=-obj.imag;
    return obj;
}

//Q2
class Integer{
    private:
        int var;
    public:
        void setValue(int a){var=a;}
        friend bool operator!(Integer& );
        friend bool operator==(Integer&,Integer&);

};
bool operator!(Integer& obj ){
    return !obj.var;
}
bool operator==(Integer& obj1,Integer& obj2){
    return obj1.var==obj2.var;
}

//Q3
class Coordinate{
    private:
        int x,y;
    public:
        void setValue(int a, int b){ x=a;y=b;}
        void showValue(){cout<<x<<","<<y<<endl;}
        friend ostream& operator<<(ostream &,Coordinate &);
        friend istream& operator>>(istream &,Coordinate &);
        friend Coordinate operator,(Coordinate&,Coordinate&);
};

Coordinate operator,(Coordinate &crd1,Coordinate &crd2){
    return (crd2);
}

//Q4
ostream& operator<<(ostream &dout,Coordinate &obj){
    dout<<obj.x<<","<<obj.y<<endl;
    return dout;
}
istream& operator>>(istream &cin,Coordinate &obj){
    cin>>obj.x>>obj.y;
    return cin;
}

//Q5
class Student{
    private:
        int rollNo;
        char name[15];
        int age;
    public:
        void setStudent(int Rolnu,char [],int age);
        void showStudent();
        bool operator==(Student& s);
};
void Student::setStudent(int Rolnu,char name[],int age){
    this->rollNo=Rolnu;
    strcpy(this->name,name);
    this->age=age;
}
void Student::showStudent(){
    cout<<"Name: "<<name<<" Age: "<<age<<" ROll Nu. "<<rollNo<<endl;
}

bool Student::operator==(Student&s){
    return (strcmp(this->name,s.name)==0 && this->age==s.age && this->rollNo==s.rollNo);
}
int main(){
    // Integer obj,obj2;
    // obj.setValue(4);
    // obj2.setValue(0);
    // cout<<!obj<<" "<<!obj2;
    // cout<<boolalpha <<endl<<(obj==obj2);

    // Coordinate c1,c2,c3;
    // cin>>c1;
    // c1.showValue();

    Student s1,s2;
    s1.setStudent(11,"rahul",23);
    s2.setStudent(11,"rahul",23);
    cout<<boolalpha<<(s1==s2);
    return 0;
}

