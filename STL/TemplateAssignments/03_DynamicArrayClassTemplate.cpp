
#include<iostream>
using namespace std;
#define INVALID_INDEX -1

template<typename X>
class DynArray{
    private:
        int capacity;
        int lastIndex;
        X *arrPtr;
    protected:
        void doubleArray();
        void halfArray();
    public:
        DynArray(int); //create array for specific size
        DynArray(DynArray &arr); //Deep copy constructor
        bool isEmpty();
        bool isFull();
        void append(X);
        int getCapacity();
        void insertAtIndex(int index, X data);
        void editElementSpecificIndex(int index,X data);
        void delElementIndex(int index);
        X getElemetnAtIndex(int index);
        int elementCount();
        int findElementIndex(X data);
        DynArray operator=(DynArray&); //Copy assignment Operator
        ~DynArray();
};

template<typename X>
void DynArray<X>::doubleArray(){
    X *temp=new X [capacity*2];
    for(int i=0;i<=lastIndex;i++){
        temp[i]=arrPtr[i];
    }
    capacity*=2;
    delete[] arrPtr;
    arrPtr=temp;
}

template<typename X>
void DynArray<X>::halfArray(){
    
    X *temp=new X [capacity/2];
    for(int i=0;i<=lastIndex;i++){
        temp[i]=arrPtr[i];
    }
    capacity/=2;
    delete[] arrPtr;
    arrPtr=temp;
}
//if capacity is < 0 then capacity will be 10 
template<typename X>
DynArray<X>::DynArray(int capacity){
    if(capacity<0)
        capacity=10;
    this->capacity=capacity;
    this->lastIndex=-1;
    arrPtr=new X[capacity];
}
//copy constructor
template<typename X>
DynArray<X>::DynArray(DynArray& arr){
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    arrPtr=new X[capacity];
    for(int i=0;i<=lastIndex;i++){
        arrPtr[i]=arr.arrPtr[i];
    }
}
//copy assignment Operator
template<typename X>
 DynArray<X> DynArray<X>::operator=(DynArray<X>& other){
    delete[] arrPtr;
    capacity=other.capacity;
    lastIndex=other.lastIndex;
    arrPtr=new X[capacity];
    for(int i=0;i<=lastIndex;i++){
        arrPtr[i]=other.arrPtr[i];
    }
}

template<typename X>
bool DynArray<X>::isEmpty(){
    return lastIndex==-1;
}

template<typename X>
bool DynArray<X>::isFull(){
    return lastIndex+1==capacity;
}

template<typename X>
void DynArray<X>::append(X data){
    if(isFull())
        doubleArray();
    else{
        arrPtr[lastIndex+1]=data;
        lastIndex++;
    }
}

template<typename X>
void DynArray<X>::insertAtIndex(int index,X data){
    if(index>lastIndex+1 || index<0)    
        throw INVALID_INDEX;
    if(isFull())
        doubleArray();
    int i;
     for(i=lastIndex;i>=index;i--){
        arrPtr[i+1]=arrPtr[i];
     }
     arrPtr[i]=data;
     lastIndex++;
}

template<typename X>
void DynArray<X>::editElementSpecificIndex(int index,X data){
    if(index>lastIndex || index<0)    
        throw INVALID_INDEX;
     arrPtr[index]=data;
}

template<typename X>
void DynArray<X>::delElementIndex(int index){
    if(index>lastIndex || index<0)    
        throw INVALID_INDEX;
     for(int i=index;i<lastIndex;i++){
        arrPtr[i]=arrPtr[i+1];
     }
     lastIndex--;
     if(capacity>1 && capacity/2-1>=lastIndex)
        halfArray();
}

template<typename X>
X DynArray<X>::getElemetnAtIndex(int index){
    if(index>lastIndex || index<0)    
        throw INVALID_INDEX;
    return arrPtr[index];

}

template<typename X>
int DynArray<X>::elementCount(){
    return lastIndex+1;
}

template<typename X>
DynArray<X>::~DynArray(){
    delete []arrPtr;
}

// if elment/data is in the array then return index otherwise return -1
template<typename X>
int DynArray<X>::findElementIndex(X data){
    for(int i=0;i<=lastIndex;i++){
        if(arrPtr[i]==data)
        return i;
    }
    return -1;
}
