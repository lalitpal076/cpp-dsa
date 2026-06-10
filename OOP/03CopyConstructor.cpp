// Copy constructor
/*1. Define a class Numbers with size and arr pointer as instance variables. Provide constructor to initialise instance members, dynamically allocate an array of given size and store address in arr variable of object. Also define destructor to deallocate memory of array. Implement deep copy using copy constructor to avoid memory issues.

2. Define a class Student and write a program to enter student details using constructor and define member function to display all the details.

3. Define a class Date with d, m, y as instance variables. Initialise members using initialisers.

4. Define a class Room for a hotel management project with room number, room type, is_AC, price as instance variables. Initialise instance variables using constructor.

5. Define a class Circle with radius as instance variable. Define two constructors in the class:
        Non-parameterised constructor
        Parameterised constructor
*/


#include<iostream>
#include<stdlib.h>
using namespace std;
//Q1
class Numbers{
    int size, *arr;
    public:
        Numbers(int size){
            this->size=size;
            // arr=(int*)calloc(size,4);
            arr=new int[size];
        }
        ~Numbers(){
            delete[] arr;
        }
        // this is the copy consturctor
        Numbers(Numbers& n){
            size=n.size;
            arr=new int[size];
            for(int i;i<size;i++){
                arr[i]=n.arr[i];
            }
        }
};

//Q2
class student{
    char name[25],email [35];
    int rollno,std;
    public:
    student(){
        cout<<"Enter Roll nu."<<endl;
        cin>>rollno;
        cout<<"Enter Name "<<endl;
        cin.ignore();
        cin.getline(name,25);
        cout<<"Enter email id "<<endl;
        cin.ignore();
        cin.getline(email,35);
        cout<<"Enter standard "<<endl;
        cin>>std;
    }
    void showdata(){
        cout<<name<<"\n"<<email<<" "<<rollno<<endl;
    }
};

//Q3
class Date
{
private:
    int d,m,y;
public:
    Date(int d, int m,int y);
    Date():d(1),m(1),y(2000){}
    ~Date();
};

Date::Date(int d, int m,int y):d(d),m(m),y(y)
{

}

//Q4
class Room
{
private:
    int room_num,price;
    char room_type[10];
    bool is_Ac;
public:
    Room(int room_no,int price,char room_type[],bool is_Ac);
};

Room::Room(int room_no,int price,char room_type[],bool is_Ac)
{
    this->room_num=room_no;
    this->price=price;
}

//Q5
class Circle
{
private:
    float radius;
public:
    Circle(float radius);
    Circle();
};

Circle::Circle(float radius){}
Circle::Circle(){}





int main(){
    student std;
    std.showdata();
}
