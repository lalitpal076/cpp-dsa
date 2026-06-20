/*    --------- Priority Queue ----------    */

    // take small number as highest priority
/*
1. Define a class PriorityQueue with node type pointer start as member variable.
  Implement PriorityQueue using singly linked list.
2. In question 1, define a constructor to initialise member variable.
3. In question 1, define a method to insert new item in the Priority Queue according to the priority number.
4. In question 1, define a method to delete highest priority element.
5. In question 1, define a method to get highest priority element.
6. In question 1, define a method to get highest priority number.
7. In question 1, define a destructor to deallocate the memory.
8. In question 1, define a method to check if Priority Queue is empty.
9. Define a logic to implement priority queue using 2 dimensional arrays.
10.Define a logic to implement min priority queue and max priority queue in the same data structure.
*/

#include<iostream>
using namespace std;
class Node{
    private:
        int data;
        int pno;
        Node *next=nullptr;
    public:
        void setData(int data){
            this->data=data;
        }
        int getData(){return data;}
        void setNext(Node *ptr){
            next=ptr;
        }
        Node *getNext(){return next;}
        int getPno(){return pno;}
        void setPno(int pno){this->pno=pno;}
};

class PriorityQueue{
    private:
        Node *start;
    public:
        PriorityQueue();
        void insert(int data,int pno);
        void deleteHighPriorityElement();
        int getHighestPElement();
        int getHighestPno();
        ~PriorityQueue();
        bool isEmpty();
};
PriorityQueue::PriorityQueue(){
    start=nullptr;
}

PriorityQueue::~PriorityQueue(){
    while (start!=nullptr)
    {
        Node *hold=start->getNext();
        delete start;
        start=hold;
    }
}

void PriorityQueue::insert(int data,int pno){
    Node *node=new Node;
    node->setData(data);
    node->setPno(pno);
    if(start==nullptr || pno<start->getPno()){
        node->setNext(start);
        start=node;
    }
    else{
        Node *rnptr=start;
        while(rnptr->getNext()!=nullptr && pno> rnptr->getNext()->getPno()){
            rnptr=rnptr->getNext();
        }
        node->setNext(rnptr->getNext());
        rnptr->setNext(node);
        
    }
}


int PriorityQueue::getHighestPElement(){
    if(isEmpty())
        return -1;
    return start->getData();  
}
int PriorityQueue::getHighestPno(){
    if(isEmpty())
        return -1;
    return start->getPno();  
}


void PriorityQueue::deleteHighPriorityElement(){
    if(isEmpty())
        return ;
    Node *delet;
    delet=start;
    start=start->getNext();
    delete delet;
}

bool PriorityQueue::isEmpty(){
    return start==nullptr;
}

