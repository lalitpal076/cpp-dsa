/* ----- Define Linked List using class Template ------*/

#include<iostream>
using namespace std;


template<typename X>
class Node{
    private:
        X data;
        Node *next=nullptr;
    public:
        void setData(X data){
            this->data=data;
        }
        X getData(){return data;}
        void setNext(Node *ptr){
            next=ptr;
        }
        Node *getNext(){return next;}
};

template<typename X>
class SLL{
    private:
        Node<X> *start;
    public:
        SLL();
        void insertDataAtFirst(X);
        void insertDataAtEnd(X);
        int findNode(X);
        void insertAtSpecificNode(Node<X> *ptr,X);
        void deleteFirst();
        void deleteLastnod();
        ~SLL();
};
template<typename X>
SLL<X>::SLL(){
    start=nullptr;
}

template<typename X>
SLL<X>::~SLL(){
    while (start!=nullptr)
    {
        Node<X> *hold=start->getNext();
        delete start;
        start=hold;
    }
}

template<typename X>
void SLL<X>::insertDataAtFirst(X data){
    Node<X> *node=new Node<X>;
    node->setData(data);
    node->setNext(start);
    start=node;
}
template<typename X>
void SLL<X>::insertDataAtEnd(X data){
    Node<X> *node=new Node<X>;
    Node<X> *runPtr=start;
    node->setData(data);
    node->setNext(nullptr);
    if(start==nullptr)
        start=node;
    else{
    for(int i=0;runPtr->getNext()!=nullptr;i++){
        runPtr=runPtr->getNext();
    }
    runPtr->setNext(node);    
    }
}
//Q5
template<typename X>
int SLL<X>::findNode(X item){
    Node<X> *runPtr=start;
    int nod=1;
    while (runPtr!=nullptr)
    {
        if(runPtr->getData()==item)
            return nod;  
        nod++;
        runPtr=runPtr->getNext();
    }
    return nod-1;  
}
//Q6
template<typename X>
void SLL<X>::insertAtSpecificNode(Node<X> *ptr,X data){
    Node <X> *node=new Node<X>;
    Node<X> *runPtr=start;
    int nodCount=1;
    node->setData(data);
    node->setNext(nullptr);
    while(runPtr!=ptr){
        runPtr=runPtr->getNext();
        nodCount++;
    }
    node->setNext(runPtr->getNext());
    runPtr->setNext(node);   
}
//Q7
template<typename X>
void SLL<X>::deleteFirst(){
    Node<X>*delt;
    delt=start;
    start=start->getNext();
    delete delt;
}
//Q8
template<typename X>
void SLL<X>::deleteLastnod(){
    Node<X> *delt;
    Node<X> *runptr;
    runptr=start;
    while (runptr->getNext()!=nullptr)
    {
        runptr=runptr->getNext();
    }
    delt=runptr;
    runptr=nullptr;
    delete delt;
}
