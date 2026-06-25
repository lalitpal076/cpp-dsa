
/* ----------- Matrix Representation of Graph ----------*/
/*
1. Define a class Graph using matrix representation with v_count, e_count and adj pointer as instance members.
2. In Question 1, define a method createGraph() to create and store adjacent node information.
3. In Question 1, define a method to print graph matrix.
4. In Question 1, define a method to print all the adjacent nodes of a given node.
5. In Question 1, define a method to check if a given node is isolated node.
6. In Question 1, define a destructor to deallocate memory.
*/

#include<iostream>
#define INVALID_NODE -1
using namespace std;

class GraphMatrix
{
private:
    int v_count;
    int e_count;
    int **adj;
public:
    GraphMatrix(/* args */);
    ~GraphMatrix();
    void createGraph(int,int);
    void printMatrix();
    void printAdjacent(int);
    bool isIsolated(int);
};

GraphMatrix::GraphMatrix()
{
    v_count=0;e_count=0;adj=nullptr;
}

GraphMatrix::~GraphMatrix()
{
    for(int i = 0; i < v_count; i++){
        delete[] adj[i];
    }
    delete[] adj;
}

void GraphMatrix::createGraph(int v_count,int e_count){
    int u,v;
    this->v_count=v_count;
    this->e_count=e_count;
    adj=new int*[v_count];
    for(int i=0;i<v_count;i++){
        adj[i]=new int[v_count];
    }
    for(int i=0;i<v_count;i++){
        for(int j=0;j<v_count;j++){
            adj[i][j]=0;
        }
    }
    for(int k=1;k<=e_count;k++){
        cout<<"\nEnter node number connecting edges: ";
        cin>>u>>v;
        adj[u-1][v-1]=1;
        adj[v-1][u-1]=1;
    }
}

void GraphMatrix::printMatrix(){
    cout<<endl;
    for(int i=0;i<v_count;i++){
        for (int j = 0; j < v_count; j++)
        {
            cout<<" "<<adj[i][j];
        }
        cout<<endl;
    }
}

void GraphMatrix::printAdjacent(int nodeNu){
    if(nodeNu>v_count||nodeNu<1)
        throw INVALID_NODE;
    cout << "\nAdjacent nodes of " << nodeNu << ":";
    for(int i=0;i<v_count;i++){
        if(adj[nodeNu-1][i]==1){
            cout<<" "<<i+1;
        }
    }

}

bool GraphMatrix::isIsolated(int nodeNu){
    if(nodeNu>v_count||nodeNu<1)
        throw INVALID_NODE;
    for(int i=0;i<v_count;i++){
        if(adj[nodeNu-1][i]!=0)
        return false;
    }
    return true;

}

int main(){
    GraphMatrix grph;
    grph.createGraph(5,4);
    cout<<"create graph chal gya\n";
    grph.printMatrix();
    cout<<"print matrix chal gya";
    grph.printAdjacent(4);
    cout<<endl;
    cout<<boolalpha<<grph.isIsolated(4);
    return 0;
}