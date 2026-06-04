#include<iostream>
using namespace std;
class Node{
    private:
        int data;
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
};

class SLL{
    private:
        Node *start;
    public:
        SLL();
        void insertDataAtFirst(int);
        void insertDataAtEnd(int);
        int findNode(int);
        void insertAtSpecificNode(int,int);
        void deleteFirst();
        void deletelastnod();
        ~SLL();
};
SLL::SLL(){
    start=nullptr;
}
void SLL::insertDataAtFirst(int data){
    Node *node=new Node;
    node->setData(data);
    node->setNext(start);
    start=node;
}
void SLL::insertDataAtEnd(int data){
    Node *node=new Node;
    Node *runPtr=start;
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
int SLL::findNode(int item){
    Node*runPtr=start;
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
void SLL::insertAtSpecificNode(int nod,int data){
    Node *node=new Node;
    Node *runPtr=start;
    int nodCount=1;
    node->setData(data);
    node->setNext(nullptr);
    while(nodCount!=nod){
        runPtr=runPtr->getNext();
        nodCount++;
    }
    node->setNext(runPtr->getNext());
    runPtr->setNext(node);   
}
//Q7
void SLL::deleteFirst(){
    Node *delt;
    delt=start;
    start=start->getNext();
    delete delt;
}
//Q8
void SLL::deletelastnod(){
    Node *delt;
    Node *runptr;
    runptr=start;
    while (runptr->getNext()!=nullptr)
    {
        runptr=runptr->getNext();
    }
    delt=runptr;
    runptr=nullptr;
    delete delt;
}
