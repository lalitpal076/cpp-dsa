
// --------------- Vector -------------
/*
1. Create a vector object and initialise it with 5 integer values. Display vector values using subscript operator.
2. Create a vector object and initialise it with 5 float values. Display vector values using at() method.
3. Create a vector object and initialise it with 5 string values. Display vector values using implicit iterator.
4. Create a vector object and initialise it with 5 integer values. Display vector values using explicit iterator.
5. Write a C++ function that returns the elements in a vector that are strictly smaller than their adjacent left and right neighbours.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void Q1(){
 vector<int> vctr={10,20,13,14,15};
 vector<int>:: iterator it;
 it=vctr.begin();
 cout<<vctr.size()<<endl;
//  cout<<"\n"<<vctr.capacity();
//  for(int i=0;i<vctr.size();i++){
//     cout<<it[i]<<" ";
//  }
 for(int i=0;i<vctr.size();i++){
    cout<<vctr[i]<<" ";
 }
//  for(auto X: vctr){
//     cout<<X<<" ";
//  }   
}

void Q2(){
 vector<float> vctr={10.11f, 20.23f, 30.02f, 45.43f, 50.07f};

 for(int i=0;i<vctr.size();i++){
    cout<<vctr.at(i)<<" ";
 }
  
}

void Q3(){
 vector<string> vctr={"Apple", "Banana", "Cherry", "Mango", "Orange"};
    for(auto str: vctr){
        cout<<str<<" ";
    }
  
}

void Q4(){
 vector<int> vctr={10,20,13,14,15};
 vector<int>:: iterator it;
 for(it=vctr.begin();it!=vctr.end();it++){
    cout<<*it<<" ";
 }

}

vector<int> Q5(){
    vector<int> vcarr={12, 25, 18, 40, 22, 35, 28, 50, 31, 45};
    vector<int> v2;
    vector<int>::iterator it;
    for(it=vcarr.begin()+1;it!=vcarr.end()-1;it++){
        if(*it<*(it-1) && *it<*(it+1))
        v2.push_back(*it);
    }
    return v2;
}
int main()
{   vector<int> v2;
    v2=Q5();
    for(auto X: v2){
        cout<<X<<" ";
    }
    cout <<endl;
    return 0;
}
