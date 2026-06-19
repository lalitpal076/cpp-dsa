/*   ------- Deque Implementation*/

/*
1. Define a class Deque with node type pointers front and rear as member variables.
 Implement using doubly linked list.
2. In question 1, define a constructor to initialise member variables.
3. In question 1, define a method to insert a new element at the front.
4. In question 1, define a method to insert a new element at the rear.
5. In question 1, define a method to delete front element.
6. In question 1, define a method to delete rear element.
7. In question 1, define a method to get front element.
8. In question 1, define a method to get rear element.
9. In question 1, define a destructor to deallocate the memory.
10. In question 1, define a method to check if deque is empty.
*/

#include<iostream>
using namespace std;
#define NOTFOUND -1;

struct Node
{
    int data;
    Node *prev,*next;
};

class Deque
{
private:
    Node *Front,*Rear;
public:
    Deque();
    ~Deque();
    void insertFront(int data);
    void insertRear(int data);
    void deleteFront();
    void deleteRear();
    int getFront();
    int getRear();
    bool isEmpty();

};

Deque::Deque()
{
    Front=nullptr;
    Rear=nullptr;
}

Deque::~Deque(){
    while (Front!=nullptr)
    {
        Node *hold=Front->next;
        delete Front;
        Front=hold;
    }
    Rear=nullptr;
}

void Deque::insertFront(int data){
    Node *node=new Node;
    node->data=data;

    if(Front==nullptr && Rear==nullptr){
        node->prev=nullptr;
        node->next=nullptr;
        Front=node; Rear=node;
    }
    else{
        Front->prev=node;
        node->next=Front;
        node->prev=nullptr;
        Front=node;
    }
}

void Deque::insertRear(int data){
    Node *node=new Node;
    node->data=data;

    if(Front==nullptr && Rear==nullptr){
        node->prev=nullptr;
        node->next=nullptr;
        Front=node; Rear=node;
    }
    else{
        Rear->next=node;
        node->prev=Rear;
        node->next=nullptr;
        Rear=node;
    }
}


void Deque::deleteFront(){
    if(Front==Rear){
        delete Front;
        Front=Rear=nullptr;
    }
    else{
    Node *hold=Front;
    Front=hold->next;
    Front->prev=nullptr;
    delete hold;
    }
}

void Deque::deleteRear(){
    if(Front==Rear){
        delete Front;
        Front=Rear=nullptr;
    }
    else{
    Node *hold=Rear;
    Rear=hold->prev;
    Rear->next=nullptr;
    delete hold;
    }
}

int Deque::getFront(){
    return Front->data;
}
int Deque::getRear(){
    return Rear->data;
}
bool Deque::isEmpty(){
    return Front==Rear;
}



