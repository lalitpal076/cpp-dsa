/*   ------- Graph List Representation --------*/

/*
1. Define a class Graph to implement linked list representation of graph. Define needful structure for node and class for AdjList.
2. Define appropriate constructors in the classes AdjList and Graph.
3. Define appropriate methods to manage linked list in AdjList.
4. Define createGraph() method in Graph class to allocate memory for array of AdjList objects.
5. Define a method addEdge() in Graph class to add a new node in adjacency list.
6. Define destructors in the classes AdjList and Graph.
7. Define a method to print graph (print values of adjacency list).
*/

#include<iostream>
using namespace std;

struct node
{
    int item;
    int vertex;
    node *next;
};
class AdjList
{
    private:
        node *start;
        int vertex;
    public:
        AdjList();
        AdjList(int);
        node* getStart();
        void setVertex(int);
        void addNode(int,int);
        void removeFirstNode();
        void printList();
        ~AdjList();
};
AdjList::AdjList(){
    start=nullptr;
}
AdjList::AdjList(int v)
{
    start=nullptr;
    vertex=v;
}
node* AdjList::getStart()
{
    return start;
}
void AdjList::setVertex(int v)
{
    vertex=v;
}
void AdjList::addNode(int v,int data)
{
    node *n=new node;
    n->item=data;
    n->vertex=v;
    n->next=start;
    start=n;
}
void AdjList::removeFirstNode()
{
    node *r;
    if(start)
    {
        r=start;
        start=start->next;
        delete r;
    }
}
void AdjList::printList()
{
    node *t;
    t=start;
    while(t)
    {
        cout<<" ("<<t->vertex<<","<<t->item<<")";
        t=t->next;
    }
}
AdjList::~AdjList()
{
    while(start)
        removeFirstNode();
}

class Graph
{
    private:
        int v_count;
        AdjList *arr;
    public:
        Graph();
        void createGraph(int);
        int getVCount();
        void printGraph();
        ~Graph();
};
Graph::Graph()
{
    v_count=0;
    arr=nullptr;
}
void Graph::createGraph(int vno)
{
    int n,v,data;
    v_count=vno;
    arr=new AdjList[v_count];
    for(int i=0;i<v_count;i++)
    {
        arr[i].setVertex(i);
        cout<<"\nHow many adjacent nodes of V"<<i<<":";
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cout<<"\nEnter vertex number: ";
            cin>>v;
            cout<<"\nEnter data item for this vertex: ";
            cin>>data;
            arr[i].addNode(v,data);
        }
    }
}
void Graph::printGraph()
{
    for(int i=0;i<v_count;i++)
    {
        cout<<endl;
        arr[i].printList();
    }
}
Graph::~Graph()
{
    delete []arr;
}