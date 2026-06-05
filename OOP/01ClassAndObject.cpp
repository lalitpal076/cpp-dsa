#include<iostream>
using namespace std;

class Complex{
    private:
        int a,b;
    public:
        void setValue(int a,int b){
            this->a=a;
            this->b=b;
        }
        void getValue(){
            cout<<a<<"+"<<b<<"i"<<endl;
        }
};

class Time{
    private:
        int hr=00,min=00,sec=00;
    public:
        void setTime(int hr,int min=00,int sec=00){
            if(hr<12 && min<60 && sec<60)
                {this->hr=hr;
                this->min=min;
                this->sec=sec;
                }else
                    cout<<"time is not right!"<<endl;
        }
        void getTime(){
            cout<<hr<<":"<<min<<":"<<sec<< endl;
        }

};

int main(){
    Complex c1;
    // c1.setValue(3,4);
    // c1.getValue();

    Time T1;
    T1.setTime(10,34,30);
    T1.getTime();

    return 0;
}