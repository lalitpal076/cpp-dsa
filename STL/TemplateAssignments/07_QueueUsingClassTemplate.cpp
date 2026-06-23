/* ----- Implement Queue Using Singly Linked List with Class Template ------*/
/*
1. Define a class Queue with node type pointers front and rear as member variables.
2. In question 1, define a constructor to initialise member variable.
3. In question 1, define a method to insert a new element at the rear in the queue.
4. In question 1, define a method to view rear element in the queue.
5. In question 1, define a method to view front element in the queue.
6. In question 1, define a method to delete the front element of the queue.
7. In question 1, define a destructor to deallocates the memory.
8. In question 1, define a method to count number of elements present in the queue.
*/

#include<iostream>
#define NOT_AVAILABLE -1
using namespace std;

template<typename T>
class Node{
    private:
        int data;
        Node<T> *next=nullptr;
    public:
        void setData(int data){
            this->data=data;
        }
        int getData(){return data;}
        void setNext(Node<T> *ptr){
            next=ptr;
        }
        Node<T> *getNext(){return next;}
};

template<typename T>
class Queue{
    private:
        Node<T> *front,*rear;
    public:
        Queue();
        void enqueue(T);
        T peekFront();
        T peekRear();
        void dequeue();
        int countElement();
        ~Queue();
};

template<typename T>
Queue<T>::Queue(){
    front=nullptr;
    rear=nullptr;
}

template<typename T>
void Queue<T>::enqueue(T data){
    Node<T> *node=new Node<T>;
    Node<T> *runPtr=front;
    node->setData(data);
    node->setNext(nullptr);
    if(front==nullptr){
        front=node;rear=node;
    }
    else{
        for(int i=0;runPtr->getNext()!=nullptr;i++){
            runPtr=runPtr->getNext();
        }
    runPtr->setNext(node);
    rear=node;    
    }
}

template<typename T>
void Queue<T>::dequeue(){
    Node<T> *del;
    del=front;
    front=front->getNext();
    if(front==nullptr) rear=nullptr;
    delete del;
}

template<typename T>
T Queue<T>::peekFront(){
    if(front==nullptr) throw NOT_AVAILABLE;
    return front->getData();
}

template<typename T>
T Queue<T>::peekRear(){
    if(front==nullptr) throw NOT_AVAILABLE;
    return rear->getData();
}

template<typename T>
int Queue<T>::countElement(){
    if(front==nullptr) return 0;
    Node<T> * runptr=front;
    int i=0;
    for(i=1;runptr->getNext()!=nullptr;i++)
        runptr=runptr->getNext();
        return i;
}