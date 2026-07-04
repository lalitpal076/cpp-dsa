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