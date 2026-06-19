/*
************* Dynamic Array Class implementation **************

1. Define a class **DynArray** to implement dynamic array data structure with member variables to store capacity of array, last index of the last filled block of the array, and a pointer to hold the address of the first block of the dynamically created array.
2. In question 1, define a parameterized constructor to create an array of specified size.
3. In question 1, define a method **doubleArray()** to increase the size of the array by double of its size.
4. In question 1, define a method **halfArray()** to decrease the size of the array by half of its size.
5. In question 1, define a method which returns the current capacity of the array.
6. In question 1, add a method to check whether an array is empty or not by returning **True** or **False**.
7. In question 1, define a method to append a new element in the array.
8. In question 1, define a method to insert a new element at specified index.
9. In question 1, define a method to edit an element at specified index.
10. In question 1, define a method to delete an element at specified index.
11. In question 1, define a method to check if the array is full by returning **true** or **false**.
12. In question 1, define a method to get element at specified index.
13. In question 1, define a method to count number of elements present in the array.
14. In question 1, define a destructor to deallocate the memory of array.
15. In question 1, define a method to find an element in the array. Return index if the element is found, otherwise return **-1**.
16. Define a copy constructor in **Array** class to perform deep copy.
17. Define a copy assignment operator in **Array** class to perform deep copy.

*/

#include<iostream>
using namespace std;
#define INVALID_INDEX -1

class DynArray{
    private:
        int capacity;
        int lastIndex;
        int *arrPtr;
    protected:
        void doubleArray();
        void halfArray();
    public:
        DynArray(int); //create array for specific size
        DynArray(DynArray &arr); //Deep copy constructor
        bool isEmpty();
        bool isFull();
        void append(int);
        int getCapacity();
        void insertAtIndex(int index, int data);
        void editElementSpecificIndex(int index,int data);
        void delElementIndex(int index);
        int getElemetnAtIndex(int index);
        int elementCount();
        int findElementIndex(int data);
        DynArray operator=(DynArray&); //Copy assignment Operator
        ~DynArray();
};

void DynArray::doubleArray(){
    int *temp=new int [capacity*2];
    for(int i=0;i<=lastIndex;i++){
        temp[i]=arrPtr[i];
    }
    capacity*=2;
    delete[] arrPtr;
    arrPtr=temp;
}

void DynArray::halfArray(){
    
    int *temp=new int [capacity/2];
    for(int i=0;i<=lastIndex;i++){
        temp[i]=arrPtr[i];
    }
    capacity/=2;
    delete[] arrPtr;
    arrPtr=temp;
}
//if capacity is < 0 then capacity will be 10 
DynArray::DynArray(int capacity){
    if(capacity<0)
        capacity=10;
    this->capacity=capacity;
    this->lastIndex=-1;
    arrPtr=new int[capacity];
}
//copy constructor
DynArray::DynArray(DynArray& arr){
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    arrPtr=new int[capacity];
    for(int i=0;i<=lastIndex;i++){
        arrPtr[i]=arr.arrPtr[i];
    }
}
//copy assignment Operator
 DynArray DynArray::operator=(DynArray& other){
    delete[] arrPtr;
    capacity=other.capacity;
    lastIndex=other.lastIndex;
    arrPtr=new int[capacity];
    for(int i=0;i<=lastIndex;i++){
        arrPtr[i]=other.arrPtr[i];
    }
;}

bool DynArray::isEmpty(){
    return lastIndex==-1;
}

bool DynArray::isFull(){
    return lastIndex+1==capacity;
}

void DynArray::append(int data){
    if(isFull())
        doubleArray();
    else{
        arrPtr[lastIndex+1]=data;
        lastIndex++;
    }
}

void DynArray::insertAtIndex(int index,int data){
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

void DynArray::editElementSpecificIndex(int index,int data){
    if(index>lastIndex || index<0)    
        throw INVALID_INDEX;
     arrPtr[index]=data;
}

void DynArray::delElementIndex(int index){
    if(index>lastIndex || index<0)    
        throw INVALID_INDEX;
     for(int i=index;i<lastIndex;i++){
        arrPtr[i]=arrPtr[i+1];
     }
     lastIndex--;
     if(capacity>1 && capacity/2-1>=lastIndex)
        halfArray();
}

int DynArray::getElemetnAtIndex(int index){
    if(index>lastIndex || index<0)    
        throw INVALID_INDEX;
    return arrPtr[index];

}

int DynArray::elementCount(){
    return lastIndex+1;
}

DynArray::~DynArray(){
    delete []arrPtr;
}

// if elment/data is in the array then return index otherwise return -1
int DynArray::findElementIndex(int data){
    for(int i=0;i<=lastIndex;i++){
        if(arrPtr[i]==data)
        return i;
    }
    return -1;
}
