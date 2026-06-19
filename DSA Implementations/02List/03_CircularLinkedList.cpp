/* ----- Circular Linked List*/
/*
1. Define a class CLL to implement Circular linked list data structure with member variable last pointer of type node.
2. In question 1, define a constructor to initialise last pointer with NULL.
3. In question 1, define a method to insert a data into the list at the beginning.
4. In question 1, define a method to insert a data into the list at the end.
5. In question 1, define a method to search a node with the given item.
6. In question 1, define a method to insert a data into the list after the specified node of the list.
7. In question 1, define a method to delete first node from the list.
8. In question 1, define a method to delete last node of the list.
9. In question 1, define a method to delete a specific node.
10. In question 1, define a destructor to deallocate memory for all the nodes in the linked list.
*/

#include<iostream>
using namespace std;

struct Node
{
    int item;
    Node*next;
};

class CLL
{
private:
    Node*Last;
public:
    CLL();
    ~CLL();

    void insertAtbeginning(int );
    void insertAtend(int );
    Node*findNode(int );
    void insertAfterSpecificNode(Node *,int);
    void deleteFirstNode();
    void deleteLastNode();
    void deleteSpecificNode(Node *);
};

//Q2
CLL::CLL()
{
    Last=nullptr;
}

CLL::~CLL()
{
    while(Last!=nullptr){
        deleteFirstNode();
    }
}

//Q3
void CLL::insertAtbeginning(int data ){
    Node* temp=new Node;
    temp->item=data;
  //when list is empty 
    if(Last==nullptr){
        temp->next=temp;
        Last=temp;
        return;
    }
  //when list is not Empty   
    temp->next=Last->next;
    Last->next=temp;
}

//Q4
void CLL::insertAtend(int data){
    Node*temp=new Node;
    temp->item=data;
    if(Last==nullptr){
        temp->next=temp;
        Last=temp;
        return;
    }
    temp->next=Last->next;
    Last->next=temp;
    Last=temp;
}

//Q5
Node* CLL::findNode(int item){
    if(Last == nullptr) return nullptr; 

    Node *runptr=Last->next;
    while(runptr!=Last){
        if(runptr->item==item)
        return runptr;
        runptr=runptr->next;
    }
    if(runptr->item==item)
        return runptr;
    return nullptr;
}

//Q6
void CLL::insertAfterSpecificNode(Node * nod,int item ){
    if(Last==nullptr){
        cout<<"List is Empty!\n";
        return;
    }
    if(nod==Last){
        insertAtend(item);
    }
    else{
        Node*temp=new Node;
        temp->item=item;
        temp->next=nod->next;
        nod->next=temp;
    }
}

//Q7
void CLL::deleteFirstNode(){
    if(Last == nullptr) return; 

    if(Last->next == Last){     
        delete Last;
        Last = nullptr;
        return;
    }

    Node* Dnod=Last->next;
    Last->next=Dnod->next;
    delete Dnod;
}

//Q8
void CLL::deleteLastNode(){
    if(Last == nullptr) return; 

    if(Last->next == Last){     
        delete Last;
        Last = nullptr;  
        return;
    }
    Node*temp=Last->next;
    while(temp->next!=Last){
        temp=temp->next;
    }
    temp->next=Last->next;
    delete Last;
    Last=temp;
}

//Q9
void CLL::deleteSpecificNode(Node *nod){
    if(nod==Last){
        delete Last;
        Last=nullptr;
    }
    else{
        Node*temp=Last;
        while(temp->next!=nod){
            temp=temp->next;
        }
        temp->next=nod->next;
        delete nod;
    }
}



