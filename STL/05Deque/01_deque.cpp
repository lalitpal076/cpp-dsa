// -------------- Deque ---------------

/*
1. Create a deque of int values taken from user and display them using explicit iterator.
2. Find the greatest element in a deque of int values.
3. Write a function to count frequency of all the elements of the deque.
4. Write a function to find the largest sorted subsequence in a deque of int values.
5. Write a function to find the max frequency element in the deque of int values.
*/


#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

void f1(){
    int size, num;
    deque<int> d1;
    cout<<"How many integer values want to enter: ";
    cin>>size;
    cout<<"\nEnter numbers: ";
    for(int i=0;i<size;i++){
        cin>>num;
        d1.push_back(num);
    }
    for(auto a:d1){
        cout<< a<<" ";
    }
}

void f2(){
    deque<int> d2={10,21,13,15,31,42,34,24,56,6,12};
    int greatest;
    greatest=*max_element(d2.begin(),d2.end());
    cout<<greatest;

}

void f3(deque<int> d){
    sort(d.begin(),d.end());
    for(auto a:d)cout<<a<<" ";
    int count=0,i=0,j=0,k=0;
    while (j<d.size())
    {   k++;
        if(d[i]==d[j]){
            count++;
            j++;
        }
        else{
            cout<<d[i]<<"-"<<count<<endl;
            i=j;
            count=0;
        }
    }
    cout<<d[i]<<"-"<<count;
}

void f4(deque<int> d){
//10,25,20,30,15,40,35,50,60,45,55,70,65,80,75
    int i=0,j,length,max_length=0,index;
    while (i<d.size())  
    {
        j=i;
        while (i<d.size()-1 && d[i]<d[i+1])
            i++;
        length=i+1-j;
        if(length>max_length){
            max_length=length;
            index=j;
        }
        i++;        
    }
    cout<<"Largest sorted subsequence is: ";
    deque<int>::iterator it;
    for(it=d.begin()+index;it!=d.begin()+index+max_length;it++){
        cout<<*it<<" ";
    }cout<<endl;
}

void f5(deque<int> d){
    sort(d.begin(),d.end());
    for(auto a:d)cout<<a<<" ";
    int i=0,value,maxfreq=0,freq=0,mxfEl;
    value=d[i];
    while (i<d.size())
    {
        if(value==d[i]){
            freq++;
            i++;
        }
        else{
            if(freq>maxfreq){
                maxfreq=freq;
                mxfEl=value;
                value=d[i];
                freq=0;
            }else{
                freq=0;
                value=d[i];
            }
        } 
    }
    if(maxfreq==1){
        cout<<"there is no max frequent ";
    }
    cout<<"max frequency element: "<<mxfEl<<"-"<<maxfreq;
}

int main(int argc, char const *argv[])
{
    deque<int> d2={10,20,10,30,40,20,10,50,30,40,20,60,10,30,20};
    deque<int> d3={5,10,20,10,15,25,25,10,10,30,5,35,35,10,40,5,45};

    f5(d3);
    return 0;
}
