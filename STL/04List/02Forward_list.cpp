// ------------ Forward List ------------
/*
1. Create an empty forward_list of int type values. Now assign four 10s and three 5s in it.
2. Create a forward_list of strings and display them in reverse order.
3. Write a function to find the total number of integers present in the forward_list which are greater than a given number.
4. Write a function to erase first element from the given forward_list which is just greater than the given element.
5. Create a forward_list to represent a polynomial expression.
*/


#include<iostream>
#include<forward_list>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


void f1(){
    forward_list<int> fl;
    fl.assign({10,10,10,10,5,5,5});
    for(int a:fl){
        cout<<a<<" ";
    }
}

void f2(){
    forward_list <string> flos={"amit" ,"sumit","rajneesh","shankar"};
    flos.reverse();
    for(string s:flos){
        cout<<s<<" ";
    }
}

int f3(forward_list<int> &flist,int value){
    int total=0;
    for(int a:flist){
        if(a>value){
            total++;
        }
    }
    return total;

}

void f4(forward_list<int> &flist,int value){
    forward_list<int>::iterator prev,curr;
    prev=flist.before_begin();
    curr=flist.begin();
    while (curr!=flist.end())
    {
        if(*curr>value){
            flist.erase_after(prev);
            return;
        }
        prev=curr;
        curr++;
    }
}

struct Term
{
    int coeff,exp;
    Term(int c,int e):coeff(c),exp(e){}
};


void f5(){
    forward_list<Term> fl;
    //3x^3-4X^2+x+10
    // fl.push_front({10,0});
    fl.assign({{3,3},{-4,2},{1,1},{10,0}});
    for(Term t:fl){
        cout<<"("<<t.coeff<<'X'<<'^'<<t.exp<<") ";
    }

}
int main(int argc, char const *argv[])
{
    forward_list<int> given_list={10,20,11,19,30,45,29,35,46,13};
    // cout<<f3(given_list,30);
    f4(given_list,20);
    for(int a:given_list){
        cout<<a<<" ";
    }
    cout<<endl;
    f5();
    return 0;
}

