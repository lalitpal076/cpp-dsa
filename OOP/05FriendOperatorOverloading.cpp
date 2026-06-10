/*  ----Friend Funciton Operator Overloading----   */

/* 
1. Make a class called Complex and write friend functions to overload the operators +, -, and *. 
2. Create a class Time with suitable variables and functions. Overload the insertion operator (<<), and the extraction operator (>>).
3. In the same Time class, also overload the assignment operator (=). 
4. Consider the following class
    class Array{int *p; int size; public: //methods}; Define (=) Operator to perform deep copy of Array Object
*/

#include<iostream>
using namespace std;

class Complex
{
private:
    int a,b;
public:
    Complex(){}
    Complex(Complex&C){a=C.a;b=C.b;cout<<"hey mai hi hu";}
    void setData(int a, int b){this->a=a;this->b=b;}
    void showData(){cout<<a<<"+"<<b<<'i';}
    friend Complex operator+(Complex,Complex);
    friend Complex operator-(Complex,Complex);
    friend Complex operator*(Complex,Complex);
};

//friend operator 
// Complex operator+(Complex C1,Complex C2){
//     Complex temp;
//     temp.a=C1.a+C2.a;
//     temp.b=C1.b+C2.b;
//     return temp;
// }
Complex operator+(Complex C1,Complex C2){
    Complex Temp;
    Temp.a=C1.a+C2.a;
    Temp.b=C1.b+C2.b;
    return C1;
}

Complex operator-(Complex C1,Complex C2){
    Complex temp;
    temp.a=C1.a-C2.a;
    temp.b=C1.b-C2.b;
    return temp;
}
Complex operator*(Complex C1,Complex C2){
    Complex temp;
    temp.a=C1.a*C2.a;
    temp.b=C1.b*C2.b;
    return temp;
}

class Time
{
private:
    int hr, min,sec;
public:
    void setTime(int hr,int min, int sec){
        this->hr=hr;
        this->min=min;
        this->sec=sec;
    }
    void showTime(){
        cout<<hr<<':'<<min<<':'<<sec<<endl;
    }
    friend ostream& operator<<(ostream&,Time&);
    friend istream& operator>>(istream&,Time&);
    Time& operator=(Time&);
    

};

//insertion operator
ostream& operator<<(ostream& dout,Time& T){
    dout<<T.hr<<':'<<T.min<<':'<<T.sec<<endl;
}

//extraction operator
istream& operator>>(istream& din,Time& T){
    din>>T.hr>>T.min>>T.sec;
}

// Assignment operator= ek special case hai → C++ standard ke mutabiq ye sirf member function ho sakta hai. frined and static ya globaly ise define nhi kr skte.
Time& Time:: operator=(Time& T1){
    this->hr=T1.hr;
    this->min=T1.min;
    this->sec=T1.sec;
    return *this;
}

//Define (=) Operator to perform deep copy of Array Object
class Array{
    private:
        int *p; int size; 
    public: 
        Array& operator=(Array& Ar);
};

Array& Array::operator=(Array& Ar){
    this->size=Ar.size;
    this->p=new int[size];
    for(int i=0;i<size;i++)
        p[i]=Ar.p[i];
    
    return *this;
}





int main(){
    Complex a,b;
    a.setData(4,6);
    b.setData(2,5);
    (a+b).showData();


    return 0;
}

