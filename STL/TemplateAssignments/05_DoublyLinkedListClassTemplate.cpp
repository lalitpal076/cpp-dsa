/* ----- Define Doubly Linked List using class Template ------*/


#include<iostream>
using namespace std;
#define NOTFOUND -1;

template<typename X>
struct Node
{
    int data;
    Node<X> *prev,*next;
};

template<typename X>
class DLL
{
private:
    Node<X> *Start;
public:
    DLL();
    ~DLL();
    void insertAtFirst(X data);
    void insertAtLast(X data);
    Node<X>* findNode(X data);
    void insertAtSpecificNode(Node<X>*temp,X data);
    void deleteFirstNode();
    void deleteLastNode();
    void deleteSpecificNode(Node<X> *ndptr);
};


template<typename X>
DLL<X>::DLL()
{
    Start=nullptr;
}

template<typename X>
DLL<X>::~DLL()
{
}

template<typename X>
void DLL<X>::insertAtFirst(X data){
    Node<X> *node=new Node<X>;
    node->data=data;
    node->prev=nullptr;
    node->next=Start;
    if(Start!=nullptr){
        Start->prev=node;
    }
    Start=node;
}

template<typename X>
void DLL<X>::insertAtLast(X data){
    Node<X> *node=new Node<X>,*runptr;
    node->data=data;
    node->next=nullptr;
    if(Start==nullptr){
        node->prev=nullptr;
        Start=node;
        return;
    }

    runptr=Start;
    while(runptr->next!=nullptr){
        runptr=runptr->next;
    }
    node->prev=runptr;
    runptr->next=node;
}

template<typename X>
Node<X>* DLL<X>::findNode(X data){
    Node<X> *runptr=Start;
    while (runptr!=nullptr)
    {
        if (runptr->data==data)
        {
            return runptr;
        }
        runptr=runptr->next;
    }
    // throw NOTFOUND;
    return nullptr;    
}

template<typename X>
void DLL<X>::insertAtSpecificNode(Node<X> *temp,X data){
    Node<X> *node=new Node<X>;
    node->data=data;
    node->prev=temp;
    if(temp!=nullptr){
        if(temp->next!=nullptr){
            temp->next->prev=node;
            node->next=temp->next;
        }else{
            temp->next=node;

        }

    }
}

template<typename X>
void DLL<X>::deleteFirstNode(){
    Node<X> *hold=Start->next;
    hold->prev=nullptr;
    delete Start;
    Start=hold;
}

template<typename X>
void DLL<X>::deleteLastNode(){
    Node<X> *runptr=Start;
    while (runptr->next!=nullptr)
    {
        runptr=runptr->next;
    }
    runptr->prev->next=nullptr;
    delete runptr;
}

template<typename X>
void DLL<X>::deleteSpecificNode(Node<X> *delnode){
    delnode->next->prev=delnode->prev;
    delnode->prev->next=delnode->next;
    delete delnode;

}



