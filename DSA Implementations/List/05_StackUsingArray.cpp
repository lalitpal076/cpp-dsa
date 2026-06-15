/*
1. Define a class Stack with capacity, top and ptr pointer as member variables. Implement stack using array.
2. In question 1, define a parameterized constructor to initialise member variables.
3. In question 1, define a method to push a new element on to the Stack.
4. In question 1, define a method to peek top element of the stack.
5. In question 1, define a method to pop the top element of the stack.
6. In question 1, define a destructor to deallocates the memory.
7. In question 1, define a method to check stack overflow.
8. In question 1, define a method to check stack underflow.
9. Define a method to reverse a stack.
10. Define a solution to keep track of minimum value element in the stack.
*/

#include<iostream>
#define STACK_OVERFLOW -1;
#define STACK_UNDERFLOW -2;

using namespace std;

class Stack{
    private:
        int capacity;
        int top;
        int *ptr;
    public:
        Stack(int);
        ~Stack();
        void push(int data);
        int peek();
        int pop();
        void reverseStack();
        int minValueInStack();
};

Stack::Stack(int cap){
    capacity=cap;
    top=-1;
    ptr=new int[capacity];
}
Stack::~Stack(){
    delete[] ptr;
}

void Stack::push(int data){
    if(top>=capacity-1){
       throw STACK_OVERFLOW;
    }
    ptr[top+1]=data;
    top++;
}

int Stack::peek(){
    if(top==-1)
        throw STACK_UNDERFLOW;
    return ptr[top];
}

int Stack::pop(){
    if(top==-1)
        throw STACK_UNDERFLOW;
    return ptr[top--];

}
void Stack::reverseStack(){
    int *temp=new int [capacity];
    for(int i=0,j=top;i<=top;i++){
        temp[i]=ptr[j--];
    }
    delete[]ptr;
    ptr=temp;
}
int Stack::minValueInStack(){
    if(top==-1)
        throw STACK_UNDERFLOW;
    int min=ptr[0];
    for(int i=0;i<=top;i++){
        if(min>ptr[i])
            min=ptr[i];
    }
    return min;
}

int main() {
    Stack s1=5;
    s1.push(10);
    s1.push(14);
    s1.push(15);
    s1.push(17);
    cout<<s1.peek()<<endl;
    s1.reverseStack();
    cout<<s1.peek();
    return 0;
}