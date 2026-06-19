/*   ------- Queue Using Arrays*/
/*
1. Define a class Queue with capacity, front, rear and ptr pointer as member variables.
2. In question 1, define a parameterzied constructor to initialise member variables.
3. In question 1, define a method to insert a new element at the rear in the queue.
4. In question 1, define a method to view rear element of the queue.
5. In question 1, define a method to view front element of the queue.
6. In question 1, define a method to delete the front element of the queue.
7. In question 1, define a destructor to deallocates the memory.
8. In question 1, define a method to check queue overflow
9. In question 1, define a method to check queue underflow.
10.In question 1, Define a method to count number of elements present in the queue.
*/

#include<iostream>
#define UNDER_FLOW -1
#define OVER_FLOW -2
using namespace std;

class Queue{
    private:
        int capacity;
        int front, rear;
        int *ptr;
    public:
        Queue(int cap);
        ~Queue();
        void enqueue(int );
        int  peekRear();
        int  peekFront();
        int  dequeue();
        bool isFull();
        bool isEmpty();
        int size();
};

Queue::Queue(int cap){
    this->capacity=cap;
    this->ptr=new int[cap];
    front=rear=-1;
}

Queue::~Queue (){
    delete[] ptr;
}
void Queue::enqueue(int data ){
    if(isFull())
        throw OVER_FLOW;
    if(front==-1) front=0;
    ptr[++rear]=data;
}
int  Queue:: peekRear(){
    if(isEmpty())
        throw UNDER_FLOW;
    return ptr[rear];
}
int  Queue:: peekFront(){
    if(isEmpty()) throw UNDER_FLOW;
    return ptr[front];
}
int  Queue:: dequeue(){
    int data;        
    if(isEmpty()) throw UNDER_FLOW;
    data=ptr[front++];
    if(front>rear)
        front=rear=-1;
    return data;

}
bool Queue:: isFull(){
    return (rear==capacity-1);
}
bool Queue:: isEmpty(){
    return (rear==-1);
}
int Queue::size(){
    return rear+1;
}