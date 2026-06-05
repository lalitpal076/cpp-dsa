/* Operator Overloading */
/*
1. Define a class Complex with appropriate instance variables and member functions. Define the following operators in the class: + (addition), - (subtraction), * (multiplication), and == (equality comparison).
2. Create a class Time which contains hour, min and second as fields. Overload greater than (>) operator to compare two Time objects.
3. In Question-2, overload pre-increment (++) and post-increment (++) operators to increment the Time object value by one second.
4. In Question-2, overload operator + to add two Time objects.
*/

#include<iostream>
using namespace std;
//Q1
class Complex{
    private:
        int a,b;
    public:
        void setdata(){
            cout<<"Enter complex number "<<endl;
            cin>>a>>b;
        }
        void showdata(){
            cout<<a<<"+"<<b<<"i"<<endl;
        }

        Complex operator+(Complex c){
            Complex temp;
            temp.a=this->a+c.a;
            temp.b=this->b+c.b;
            return temp;
        }

        Complex operator-(Complex c){
            Complex temp;
            temp.a=this->a-c.a;
            temp.b=this->b-c.b;
            return temp;
        }

        Complex operator*(Complex C){
            Complex temp;
            temp.a=a*C.a-b*C.b;
            temp.b=a*C.b+b*C.a;
            return temp;
        }

        bool operator==(Complex c){
            if(a==c.a && b==c.b)
             return true;
            else
             return false;
        }
};

//Q2
class Time{
    private:
        int hour, min, sec;
    public:
        Time():hour(0),min(0),sec(0){}
        void setdata(){
            cout<<"Enter Time in hr min sec "<<endl;
            cin>>hour>>min>>sec;
        }
        void shodata(){
            cout<<endl<<hour<<":"<<min<<":"<<sec<<endl;
        }
        bool operator>(Time T){
            if(hour>T.hour)
                return true;
            else if(hour<T.hour)
                return false;
            else if(min>T.min)
                return true;
            else if(min<T.min)
                return false;
            else if(sec>T.sec)
                return true;
            else
                return false;

        }
//Q3 pre-increment and post-increment in by one second
        Time operator++(int){ // post increment
            Time t=*this;
            sec++;
            min+=sec/60;
            sec=sec%60;
            hour+=min/60;
            min=min%60;
            return t;
        }

        Time operator++(){ // pre increment
            
            sec++;
            min+=sec/60;
            sec=sec%60;
            hour+=min/60;
            min=min%60;
            return *this;
        }
        Time operator+(Time t1);
        
};

//Q4 overload operator+ to add two time objects.
Time Time::operator+(Time t1){
            Time temp;
            temp.sec=sec+t1.sec;
            temp.min+=temp.sec/60;
            temp.sec=temp.sec%60;
            temp.min+=min+t1.min;
            temp.hour+=temp.min/60;
            temp.min=temp.min%60;
            temp.hour+=hour+t1.hour;
            return temp;
}

int main(){
    Time a1,a2,a3;
    a1.setdata();
    a2.setdata();
    a3=a1+a2;
    a3.shodata();
}