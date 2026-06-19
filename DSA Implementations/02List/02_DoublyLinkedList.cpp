#include<iostream>
using namespace std;
#define NOTFOUND -1;

struct Node
{
    int data;
    Node *prev,*next;
};

class DLL
{
private:
    Node *Start;
public:
    DLL();
    ~DLL();
    void insertAtFirst(int data);
    void insertAtLast(int data);
    Node* findNode(int data);
    void insertAtSpecificNode(Node*temp,int data);
    void deleteFirstNdoe();
    void deleteLastNode();
    void deleteSpecificNode(Node *ndptr);
};

DLL::DLL()
{
    Start=nullptr;
}

DLL::~DLL()
{
}

void DLL::insertAtFirst(int data){
    Node *node=new Node;
    node->data=data;
    node->prev=nullptr;
    node->next=Start;
    if(Start!=nullptr){
        Start->prev=node;
    }
    Start=node;
}

void DLL::insertAtLast(int data){
    Node *node=new Node,*runptr;
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

Node* DLL::findNode(int data){
    Node *runptr=Start;
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

void DLL::insertAtSpecificNode(Node *temp,int data){
    Node *node=new Node;
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

void DLL::deleteFirstNdoe(){
    Node *hold=Start->next;
    hold->prev=nullptr;
    delete Start;
    Start=hold;
}

void DLL::deleteLastNode(){
    Node *runptr=Start;
    while (runptr->next!=nullptr)
    {
        runptr=runptr->next;
    }
    runptr->prev->next=nullptr;
    delete runptr;
}

void DLL::deleteSpecificNode(Node *delnode){
    delnode->next->prev=delnode->prev;
    delnode->prev->next=delnode->next;
    delete delnode;

}



