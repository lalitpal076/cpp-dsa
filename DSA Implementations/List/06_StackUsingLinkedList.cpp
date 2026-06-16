
/*  ----- Stack Using Linked List -----*/
/*
1. Define a class Stack with node type pointer top as member variable. Implement stack using linked list.
2. In question 1, define a constructor to initialise member variable.
3. In question 1, define a method to push a new element on to the Stack.
4. In question 1, define a method to peek top element of the stack.
5. In question 1, define a method to pop the top element of the stack.
6. In question 1, define a destructor to deallocates the memory.
7. Define a method to reverse a stack.
8. Define a method to check whether a given number is a palindrome or not using stack.
9. Define a method to convert infix to postfix expression.
10. Define a method to evaluate postfix expression.

*/


#include<iostream>
#define STACK_UNDERFLOW -1
using namespace std;
class Node{
    private:
        int data;
        Node *next=nullptr;
    public:
        void setData(int data){
            this->data=data;
        }
        int getData(){return data;}
        void setNext(Node *ptr){
            next=ptr;
        }
        Node *getNext(){return next;}
};

class Stack{
    private:
        Node *top;
    public:
        Stack();
        void push(int);
        int pop();
        int peek();
        bool isEmpty();
        ~Stack();
};
Stack::Stack(){
    top=nullptr;
}

Stack::~Stack(){
    while (top!=nullptr)
    {
        Node * delt;
        delt=top;
        top=delt->getNext();
        delete delt;    
    }
    
}

bool Stack::isEmpty(){
    return top==nullptr;  
}

void Stack::push(int data){
    Node *node=new Node;
    node->setData(data);
    node->setNext(top);
    top=node;
}

int Stack::peek(){
    if(top==nullptr)
        throw STACK_UNDERFLOW;
    return top->getData();
}

int Stack::pop(){
    if(top==nullptr)
        throw STACK_UNDERFLOW;
    int data;
    Node *delt;
    delt=top;
    data=delt->getData();
    top=delt->getNext();
    delete delt;
    return data;
}


void stackReverse(Stack & stk){
    Stack s1;
    Stack s2;
    while (!stk.isEmpty())
    {
        s1.push(stk.pop());
    }
    while (!s1.isEmpty())
    {
        s2.push(stk.pop());
    }
    while (!s2.isEmpty())
    {
        stk.push(stk.pop());
    }

    
}

bool isPalindrome(int number){
    Stack s1;    
    int num=number;
    while (number!=0)
    {
        s1.push(number%10);
        number/=10;
    }
    
    while (num!=0)
    {
        if(num%10!=s1.pop())
            break;
        num/=10;
    }
    if(num==0)
        return true;
    else
        return false;

}

void infixToPostFix(){

}

int main()
{
    cout<<boolalpha<<isPalindrome(124321);
    return 0;
}
