#include<iostream>
using namespace std;
#define ARRAY_OVERFLOW 1
#define INVALID_INDEX -1

class Array{
    private:
        int capacity;
        int lastIndex;
        int *arrPtr;
    public:
        Array(int);
        bool isEmpty();
        bool isFull();
        void append(int);
        void insertAtIndex(int index, int data);
        void editElementSpecificIndex(int index,int data);
        void delElementIndex(int index);
        int getElemetnAtIndex(int index);
        int elementCount();
        int findElementIndex(int data);
        ~Array();
};

//if capacity is < 0 then capacity will be 10 
Array::Array(int capacity){
    if(capacity<0)
        capacity=10;
    this->capacity=capacity;
    this->lastIndex=-1;
    arrPtr=new int[capacity];
}

bool Array::isEmpty(){
    return lastIndex==-1;
}

bool Array::isFull(){
    return lastIndex+1==capacity;
}

void Array::append(int data){
    if(isFull())
        throw ARRAY_OVERFLOW;
    else{
        arrPtr[lastIndex+1]=data;
        lastIndex++;
    }
}

void Array::insertAtIndex(int index,int data){
    if(index>lastIndex+1 || index<0)    
        throw INVALID_INDEX;
    if(isFull())
        throw ARRAY_OVERFLOW;
    int i;
     for(i=lastIndex;i>=index;i--){
        arrPtr[i+1]=arrPtr[i];
     }
     arrPtr[i]=data;
     lastIndex++;
}

void Array::editElementSpecificIndex(int index,int data){
    if(index>lastIndex || index<0)    
        throw INVALID_INDEX;
     arrPtr[index]=data;
}

void Array::delElementIndex(int index){
    if(index>lastIndex || index<0)    
        throw INVALID_INDEX;
     for(int i=index;i<lastIndex;i++){
        arrPtr[i]=arrPtr[i+1];
     }
     lastIndex--;
}

int Array::getElemetnAtIndex(int index){
    if(index>lastIndex || index<0)    
        throw INVALID_INDEX;
    return arrPtr[index];

}

int Array::elementCount(){
    return lastIndex+1;
}

Array::~Array(){
    delete []arrPtr;
}

// if elment/data is in the array then return index otherwise return -1
int Array::findElementIndex(int data){
    for(int i=0;i<=lastIndex;i++){
        if(arrPtr[i]==data)
        return i;
    }
    return -1;
}
