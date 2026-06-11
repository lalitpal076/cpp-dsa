/*  ------- Circular Doubly Linked List -------*/
/*
1. Define a class CCDLL to implement Circular Doubly linked list data structure with member variable start pointer of type node.
2. In question 1, define a constructor to initialise start pointer with NULL.
3. In question 1, define a method to insert a data into the list at the beginning.
4. In question 1, define a method to insert a data into the list at the end.
5. In question 1, define a method to search a node with the given data.
6. In question 1, define a method to insert a data into the list after the specified node of the list.
7. In question 1, define a method to delete first node from the list.
8. In question 1, define a method to delete last node of the list.
9. In question 1, define a method to delete a specific node.
10. In question 1, define a destructor to deallocate memory for all the nodes in the linked list.
*/

class Node
{
    public:
    int data;
    Node *prev,*next;
};

class CDLL
{
private:
    Node *Start;
public:
    CDLL();
    ~CDLL();
    void insertAtbeginning(int data);
    void insertAtend(int data);
    Node* findNode(int data);
    void insertAfterSpecificNode(Node*temp,int data);
    void deleteFirstNdoe();
    void deleteLastNode();
    void deleteSpecificNode(Node *ndptr);
};

CDLL::CDLL()
{
    Start=nullptr;
}

CDLL::~CDLL()
{
}


//Q3
void CDLL::insertAtbeginning(int data ){
    Node* temp=new Node;
    temp->data=data;
  //when list is empty 
    if(Start==nullptr){
        temp->next=temp;
        temp->prev=temp;
        Start=temp;
        return;
    }
  //when list is not Empty   
    temp->next=Start;
    Start->prev->next=temp;
    temp->prev=Start->prev;
    Start->prev=temp;
    Start=temp;    
}

//Q4
void CDLL::insertAtend(int data){
    Node *node=new Node,*runptr;
    node->data=data;
    if(Start==nullptr){
        node->prev=node;
        node->next=node;
        Start=node;
        return;
    }
    node->prev=Start->prev;
    Start->prev->next=node;
    node->next=Start;
    Start->prev=node;
}

//Q5
Node* CDLL::findNode(int data){
    Node *runptr=Start;
    if(runptr->data==data)
        return runptr;
    
    while (runptr!=Start->prev)
    {
        if (runptr->data==data)
        {
            return runptr;
        }
        runptr=runptr->next;
    }
    if(runptr->data==data)
        return runptr;
    return nullptr;    
}

//Q6
void CDLL::insertAfterSpecificNode(Node *node,int data){
    Node *temp=new Node,*rnptr;
    temp->data=data;

    if(node==Start->prev){
        insertAtend(data);
        return;
    }

    temp->next=node->next;
    node->next->prev=temp;
    temp->prev=node;
    node->next=temp;
}

//Q7
void CDLL::deleteFirstNdoe(){
    if(Start==nullptr)return;

    if(Start->next == Start){
        delete Start;
        Start = nullptr;
        return;
    }
    Node *hold=Start->next;
    Start->prev->next=Start->next;
    hold->prev=Start->prev;
    delete Start;
    Start=hold;
}

//Q8
void CDLL::deleteLastNode(){
    if(Start==nullptr)return;

    if(Start->next == Start){
        delete Start;
        Start = nullptr;
        return;
    }

    Node *lastNode=Start->prev;
    lastNode->prev->next=Start;
    Start->prev=lastNode->prev;
    delete lastNode;
}

//Q9
void CDLL::deleteSpecificNode(Node *delnode){
    if(Start==nullptr)return;

    if(Start == delnode){
        deleteFirstNdoe();
        return;
    }
    if(Start->prev==delnode){
        deleteLastNode();
        return;
    }
    delnode->next->prev=delnode->prev;
    delnode->prev->next=delnode->next;
    delete delnode;
}


