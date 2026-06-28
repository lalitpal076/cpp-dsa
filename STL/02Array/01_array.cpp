// ------------ array class -------------
/*
1. Create an array object for int values of size 5. Print array elements from right to left using explicit iterator
2. Create an array object for float values of size 5. Calculate average of numbers and display it.
3. Create an array object for int values of size 10. Take input from user. Find the greatest element of the array.
4. Create an array object for Complex type values of size 5. Write a function to input values, display values. Also define a method to calculate sum of all the complex numbers.
5. Create an array for int values of size 10. Initialise it with some values. Now sort array elements.
*/
#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

void Q1(){
    array<int,5> arr={10,20,30,45,50};
    array<int,5>::reverse_iterator rit;
    for(rit=arr.rbegin();rit!=arr.rend();rit++){
        cout<<*rit<<" ";
    }
}

float Q2(){
    array<float,5> arr={10.11f,20.23f,30.02f,45.43f,50.07f};
    array<float,5>::iterator it;
    
    float average, sum=0;
    for(it=arr.begin();it!=arr.end();it++){
        sum+=*it;
    }
    cout<<"array size is: "<<arr.size()<<endl;
    return average=sum/arr.size();
}

float Q3(){
    array<float,10> arr;
    array<float,10>::iterator it;
    cout<<"Enter 10 values: ";
    for(it=arr.begin();it!=arr.end();it++){
        cin>>*it;
    }
    float greatest=*arr.begin();
    for(it=arr.begin()+1;it!=arr.end();it++){
        if(greatest<*it)
            greatest=*it;
    }
    return greatest;

}

class Complex{
    private:
        int real, img;
    public:
        Complex(int real,int img):real(real),img(img){}
        void showValue(){
            cout<<real<<"+"<<img<<"i"<<endl;
        }
        Complex operator+(Complex&c1){
            Complex temp(0,0);
            temp.real=this->real+c1.real;
            temp.img=this->img+c1.img;
            return temp;
        }
};

void Q4(){
    Complex sumComplex(array<Complex,5>);
    array<Complex,5> arr={
                            Complex(3,4),
                            Complex(5,2),
                            Complex(2,6),
                            Complex(3,7),
                            Complex(5,1),
    };
    Complex Sum=sumComplex(arr);
    Sum.showValue();
}
Complex sumComplex(array<Complex,5> arrComplex){
    Complex accumulate(0,0);
    for(auto X:arrComplex){
        accumulate=accumulate+X;
    }
    return accumulate;
}

void Q5(){
    array<int,10> arr={10,11,3,4,2,1,8,13,21,18};
    sort(arr.begin(),arr.end());
    for(auto x:arr)
        cout<<x<<" ";
}

int main()
{
    Q5();
    return 0;
}
