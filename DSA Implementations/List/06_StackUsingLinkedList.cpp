
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
*/


#include<iostream>
#include<string>
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

//create a Array stl class 
template <typename T>
class Array{
    private:
        int cap;
        T *arr;
    protected:
        void doubelArray(){
            if(filledIndex==cap-1){
                cap*=2;
                T *temp=new T[cap];
                for(int i=0;i<=filledIndex;i++)
                    temp[i]=arr[i];
                delete[] arr;
                arr=temp;
            }}
        void halfArray(){
            if(filledIndex==cap/2-1){
                cap/=2;
                T *temp=new T[cap];
                for(int i=0;i<=filledIndex;i++)
                    temp[i]=arr[i];
                delete[] arr;
                arr=temp;
            }
        }
    public:
        int length;
        int filledIndex=-1;
        Array(){this->cap=20; length=cap-1; arr=new T[cap];}
        ~Array(){delete[] arr;}
        void push(T data){ doubelArray();if(filledIndex < length)arr[++filledIndex]=data;}
        T pop(){if(filledIndex>=0)return arr[filledIndex--]; else throw    STACK_UNDERFLOW;}
        T getValue(int index){return arr[index];}
        T top(){return arr[filledIndex];}
        void insertValue(int index, T value){arr[index]= value;}
};

int precedence(char op){
    switch (op)
    {
    case '+':
        return 1;
        break;
    
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    default:
        return 0;
        break;
    }
}
// "A+B*C"
bool isOperator(char ch){
    string expr="+-*/()";
    return (expr.find(ch)!=string::npos?1:0);
}
void infixToPostFix(string expression){
    int length=expression.length();
    Array<char> postFix;
    Array<char> stack;

    for(int i=0;i<length;i++){
        if(expression[i]=='(') // handle open parenthesis
            stack.push(expression[i]);

        else if(!isOperator(expression[i]))// handle numbers
            postFix.push(expression[i]);

        else if(isOperator(expression[i]) && expression[i]!=')'){
            if(stack.filledIndex==-1){
                stack.push(expression[i]);
            }
            else{
                while(precedence(stack.top())>=precedence(expression[i]) ){
                    postFix.push(stack.pop());
                }
                if(precedence(stack.top())<precedence(expression[i]) )
                    stack.push(expression[i]);
            }
        }
        else if(expression[i]==')' && stack.filledIndex!=-1){
            while(stack.top()!='('){
                postFix.push(stack.pop());
            }
            stack.pop();
        }  
    }  
    while(stack.filledIndex!=-1){
        postFix.push(stack.pop());
    }

    for(int i=0;i<=postFix.filledIndex;i++){
        cout<<postFix.getValue(i)<<" ";
    }
}

int main()
{
    infixToPostFix("(A+/D-B*C)");
    return 0;
}
