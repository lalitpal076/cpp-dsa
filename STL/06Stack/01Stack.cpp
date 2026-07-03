 // ----------------- Stack ---------------
/*
1. Check if a string is a palindrome using stack.
2. Reverse a stack of strings.
3. Check for balanced brackets in an expression. For example, input is “[{()}({})]”, output is balanced. Input is “[{()}]”, output is not balanced.
4. Write a function to delete middle element of the stack.
5. Implement Tower of Hanoi problem using stack through iteration.
*/

#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<stack>
using namespace std;
bool isPalindrome(string str)
{
    int len =str.size();
    stack <char,vector<char>> s1;
    for (int x=0;x<len/2;x++)
    {
        s1.push(str.back());
        str.pop_back();
    }
    if(len%2) //odd length string
        str.pop_back();
    while(!str.empty())
    {
        if(str.back()!=s1.top())
            return false;
        str.pop_back();
        s1.pop();
    }
    return true;
}
void reverse_stack(stack <string> &str)
{
    stack<string>temp;
    while(!str.empty())
    {
        temp.push(str.top());
        str.pop();
    }
    str=temp;
}
int getCode(char ch)
{
    switch(ch)
    {
        case '[':
            return 1;
        case '{':
            return 2;
        case '(':
            return 3;
        case ']':
            return -1;
        case '}':
            return -2;
        case ')':
            return -3;
        default:
            return 0;
    }
}
bool balanced_brackets(string str)
{
    char x;
    if(str.size()%2)
        return false;
    stack<char,vector<char>> s1;
    for(char ch:str)
    {
        if(ch=='['||ch=='{'||ch=='(')
            s1.push(ch);
        if(ch==']'||ch=='}'||ch==')')
        {
            x=s1.top();
            if(getCode(ch) != -getCode(x))
                return false;
            s1.pop();
        }
    }
    return true;

}
void delete_middle(stack<string> &str)
{
    int len=str.size();
    stack<string>temp;
    if(len%2)
    {
        for(int x=len-1;x>=0;x--)
        {
            if(len/2==x)
            {
                str.pop();
                continue;
            }
            temp.push(str.top());
            str.pop();
        }
        while(!temp.empty())
        {
            str.push(temp.top());
            temp.pop();
        }
    }
}

struct Move{
    int n;
    char beg;
    char end;
    char aux;
    bool goingUp;
};
void iterativeTOH(int n,char beg, char end, char aux)
{
    stack<Move>moves;
    moves.push({n,beg,end,aux,true});
    Move currentMove;
    while(!moves.empty()){
        currentMove = moves.top();
        moves.pop();

        if(currentMove.n==1)
            cout<<"Move disk from "<<currentMove.beg<<" to "<<currentMove.end<<endl;
        else
        {
            if(currentMove.goingUp){
                moves.push({currentMove.n-1,currentMove.aux,currentMove.end,currentMove.beg,false});
                moves.push({1,currentMove.beg,currentMove.end,currentMove.aux,true});
                moves.push({currentMove.n-1,currentMove.beg,currentMove.aux,currentMove.end,false});
            }
            else
            {
                moves.push({currentMove.n-1,currentMove.aux,currentMove.end,currentMove.beg,true});
                moves.push({1,currentMove.beg,currentMove.end,currentMove.aux,false});
                moves.push({currentMove.n-1,currentMove.beg,currentMove.aux,currentMove.end,true});
                
            }
        }
    }
}
int main()
{
    iterativeTOH(4,'A','C','B');
    cout<<endl;
    return 0;
}