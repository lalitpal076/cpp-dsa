#include"CLL.h"
using namespace std;


void clearScreen() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);
    FillConsoleOutputCharacter(hOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
    SetConsoleCursorPosition(hOut, coord);
}


//Node 
// struct item
// {
//     char name[20];
//     int empId;
//     int age; 
//     char mail[25];char contanctNu[12];  
//     void viewitem();
//     void getinput();
// };
//Item Node Functions Definitions
void item::viewitem(){
    cout<<"Employee ID  : "<<empId<<"\n";
    cout<<"Employee Name: "<<name<<"\n";
    cout<<"Employee Age : "<<age<<"\n";
    cout<<"Employee Mail: "<<mail<<"\n";
    cout<<"Employee Phon: "<<contanctNu<<"\n---------------------------------------------------------------------\n\n";
}
void item::getinput(int emp){
    cout<<"                    ---- Enter the Employee details ----\n";
    cout<<"Name: ";
    cin>>name; cout<<"Age: ";
    cin>>age; cout<<"Mail: ";
    cin>>mail;cout<<"Contact Nu. ";
    cin>>contanctNu;
    empId=emp;
}

// struct Node
// {
//     item data;
//     Node*next;
// };

// class CLL
// {
// private:
//     static int totalEmp;
//     Node*Last;
// public:
//     CLL();
//     ~CLL();

//     void insertAtstart( item );
//     void insertAtlast(item );
//     Node*findNode(item );
//     void insertAfterSpecificNode(Node *,item);
//     void deleteFirstNode();
//     void deleteLastNode();
//     void deleteSpecificNode(Node *);
// };
int CLL::totalEmp=0;
CLL::CLL(/* args */)
{
    Last=nullptr;
    totalEmp=0;
}

CLL::~CLL()
{
    while(Last!=nullptr){
        deleteFirstNode();
    }
}

//CLL Functions Definitions
void CLL::PrintListData(){
        Node *rnptr=Last->next;
        do
        {   rnptr->data.viewitem();
            rnptr=rnptr->next;
        } while (rnptr!=Last->next);
}
void CLL::insertAtstart( item data ){
    Node* nod=new Node;
    nod->data=data;
    //when list is empty 
    if(Last==nullptr){
        nod->next=nod;
        Last=nod;
        totalEmp++;
        return;
    }
    nod->next=Last->next;
    Last->next=nod;
    totalEmp++;

}

void CLL::insertAtlast(item data){
    Node*nod=new Node;
    nod->data=data;
    if(Last==nullptr){
        nod->next=nod;
        Last=nod;
        totalEmp++;
        return;
    }
    nod->next=Last->next;
    Last->next=nod;
    Last=nod;
    totalEmp++;

}

void CLL::insertAfterSpecificNode(Node * nod,item data){
    if(Last==nullptr){
        cout<<"List is Empty!\n";
        return;
    }
    if(nod==Last){
        insertAtlast(data);
    }
    else{
        Node*temp=new Node;
        temp->data=data;
        temp->next=nod->next;
        nod->next=temp;
        totalEmp++;
    }

}

void CLL::listTraverse(){
    
    if(Last==nullptr){
        cout<<"[null]<---(LAST)\n";         
        return ;
    }
    else{
        Node *rnptr=Last->next;
        do
        {   cout<<"["<<rnptr->data.empId<<"]-->";
            rnptr=rnptr->next;
        } while (rnptr!=Last->next);
        cout<<"["<<Last->next->data.empId<<"] (LAST)";
    }
    return ;
}

Node* CLL::findNode(int empId){
    if(Last == nullptr) return nullptr; 
    Node *runptr=Last->next;
    while(runptr!=Last){
        if(runptr->data.empId==empId)
        return runptr;
        runptr=runptr->next;
    }
    if(runptr->data.empId==empId)
    return runptr;
    return nullptr;
}

void CLL::deleteFirstNode(){
    if(Last == nullptr) return; 

    if(Last->next == Last){     
        delete Last;
        Last = nullptr;
        totalEmp--;
        return;
    }

    Node* Dnod=Last->next;
    Last->next=Dnod->next;
    delete Dnod;
    totalEmp--;

}

void CLL::deleteLastNode(){
    if(Last == nullptr) return; 

    if(Last->next == Last){     
        delete Last;
        Last = nullptr;  
        totalEmp--;
        return;
    }
    Node*Dnod=Last->next;
    while(Dnod->next!=Last){
        Dnod=Dnod->next;
    }
    Last=Dnod;
    delete Dnod->next;
    totalEmp--;

}
void CLL::deleteSpecificNode(Node *nod){
    if(nod==Last){
        delete Last;
    }
    else{
        Node*temp=Last;
        while(temp->next!=nod){
            temp=temp->next;
        }
        temp->next=nod->next;
        delete nod;
        totalEmp--;
    }

}



