/*Hybrid INheritance*/
#include<iostream>
using namespace std;
class A
{
public:
    void f1(){
        cout<<"A->f1() "<<endl;
    }
};

class B1:public A
{
public:
    void f2(){
        cout<<"B1->f2() "<<endl;
    }
    void f3(int a){cout<<"B1->f3()"<<endl;}
};

class B2:public A 
{
public:
    void f3(){
        cout<<"B2->f3() "<<endl;
    }
};
 
class C:public B1,public B2
{
public:
    void f4(){
        cout<<"C->f4() "<<endl;
    }
};

int main(){
    C c1; int a;
    c1.f4();
    c1.f3(a);// this is occure because of name conflict ambiguity problem
    c1.f1(); // this problem is occurign because of diamong problem 
}

/*---- Diamond Problem ----*/
class E{
    public:
    void f1();
};

class F1:public virtual E{
    public:
    void f2();
};
class F2:virtual public E{
    public:
    void f3();
};
class G:public F1,public F2{
    public:
    void f1(); //hre if we don't mention virtual f1 cal create an compiler error because it for a diamond problem
};