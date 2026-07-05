// -------------- Queue -------------
/*
1. Implement stack using queue.
2. Implement priority queue with the given priority range from 1 to N. [Use vector of queues]
3. Given an integer k and a queue of integers. Write a program to reverse the order of the first k elements of the queue.
4. Implement breadth first search algorithm to traverse a graph.
5. Given a square chessboard of N x N size, the position of the Knight and the position of a target are given. Write a program to find out the minimum steps a Knight will take to reach the target position.
*/


#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class Stack
{
    private:
        queue <int> top;
    public:
        bool isEmpty();
        void push(int);
        int peek_top();
        void pop();
};

bool Stack::isEmpty()
{
    return top.empty();
}

void Stack::push(int value)
{
    top.push(value);
}

int Stack::peek_top()
{
    if(top.empty())
        throw -1;
    return top.back();
}

void Stack::pop()
{
    queue <int> temp;
    int len = top.size();
    while(!top.empty())
    {
        if(len == 1)    {
            top.pop();
            break;
        }
        temp.push(top.front());
        top.pop();
        len--;
    }
    if(top.empty())
        top = temp;
}


//Q2
class PriorityQueue
{
private:
    int Capacity;
    vector<queue<int>> pq;
public:
    PriorityQueue(int mxp):Capacity(mxp),pq(mxp){}
    ~PriorityQueue();
    void push(int pno, int data);
    void pop();
    int getHighestPno();
    int get_item();
    bool isEmpty();
};

void PriorityQueue::push(int pno, int data){
    if(pno>0 && pno<Capacity){
        pq[pno-1].push(data);
    }else{
        cout<<"invalid priority \n";
    }
}

void PriorityQueue::pop(){
    for(int x=Capacity-1;x>=0; x--)
        if(!pq[x].empty()){
            pq[x].pop();
            break;
        }
}

int PriorityQueue:: getHighestPno(){
    for(int x=Capacity-1;x>=0; x--)
        if(!pq[x].empty()){
            return x;
        }
}

int PriorityQueue::get_item(){
    for(int x=Capacity-1;x>=0; x--)
        if(!pq[x].empty()){
            return pq[x].front();
        }
}

bool PriorityQueue::isEmpty(){
    for(int x=Capacity-1;x>=0; x--)
        if(!pq[x].empty()){
            return false;
        }
    return true;
}


 


int main()
{
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.pop();
    cout<<s1.peek_top()<<endl;
    return 0;
}