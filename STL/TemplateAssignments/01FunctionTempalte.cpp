#include<iostream>
using namespace std;

//Q1 function template 
template <typename X>
X big(X a,X b){
    if(a>b)
        return a;
    else
     return b;
}
// Q2 small value
template <typename X>
X small(X a,X b){
    if(a<b)
        return a;
    else
     return b;
}

//Q3 Function template to print values of an array
template<class X>
void printArray(X a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<endl;
    }
}

//Q4 function template to sort an array of any type

template<typename X>
void SortArray(X arr[],int size){
    X temp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }
    }
    cout<<"Sorted array: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

//Q4 Function template for finding greatest elemnent among the array of any type
template<typename T>
T findGreatest(T arr[],int size){
    T GreatestElement;
    for(int i=0;i<size-1;i++){
        if(arr[i]<arr[i+1]){
            GreatestElement=arr[i+1];
        }
    }
    return GreatestElement;
}

int main(){
    int arr[]={101, 18, 23, 27, 34, 39, 42, 48, 53, 59, 64, 71, 78, 85, 92, 99};
    SortArray(arr,16);
    cout<<"\nGreatest Element among the array: ";
    cout<<findGreatest(arr,16);
    // cout<<small(10,20);
    return 0;
}