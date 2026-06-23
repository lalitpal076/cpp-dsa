
/*  ----- Stack Using Linked List with Class Template -----*/
/*
1. Define a class Stack with node type pointer top as member variable. Implement stack using linked list.
2. In question 1, define a constructor to initialise member variable.
3. In question 1, define a method to push a new element on to the Stack.
4. In question 1, define a method to peek top element of the stack.
5. In question 1, define a method to pop the top element of the stack.
6. In question 1, define a destructor to deallocates the memory.
7. Define a method to reverse a stack.
8. Define a method to check whether a given number is a palindrome or not using stack.
*/


#include<iostream>
#include<string>
#define STACK_UNDERFLOW -1

using namespace std;

template<typename X>
class Node{
    private:
        int data;
        Node<X>*next=nullptr;
    public:
        void setData(int data){
            this->data=data;
        }
        int getData(){return data;}
        void setNext(Node<X>*ptr){
            next=ptr;
        }
        Node<X>*getNext(){return next;}
};

template<typename X>
class Stack{
    private:
        Node<X>*top;
    public:
        Stack();
        void push(X);
        X pop();
        X peek();
        bool isEmpty();
        ~Stack();
};
template<typename X>
Stack<X>::Stack(){
    top=nullptr;
}

template<typename X>
Stack<X>::~Stack(){
    while (top!=nullptr)
    {
        Node<X>* delt;
        delt=top;
        top=delt->getNext();
        delete delt;    
    }
    
}

template<typename X>
bool Stack<X>::isEmpty(){
    return top==nullptr;  
}

template<typename X>
void Stack<X>::push(X data){
    Node<X>*node=new Node<X>;
    node->setData(data);
    node->setNext(top);
    top=node;
}

template<typename X>
X Stack<X>::peek(){
    if(top==nullptr)
        throw STACK_UNDERFLOW;
    return top->getData();
}

template<typename X>
X Stack<X>::pop(){
    if(top==nullptr)
        throw STACK_UNDERFLOW;
    int data;
    Node<X>*delt;
    delt=top;
    data=delt->getData();
    top=delt->getNext();
    delete delt;
    return data;
}


template<typename X>
void stackReverse(Stack<X> & stk){
    Stack <X>s1;
    Stack <X>s2;
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

template<typename X>
bool isPalindrome(int number){
    Stack<X> s1;    
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


