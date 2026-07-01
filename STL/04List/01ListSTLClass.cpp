//------------ LIST ------------

/*
1. Create a list of string values and display all the elements in reverse order.
2. Write a function to create a list from a given vector of integers.
3. Find the greatest number in a given list of integers.
4. Write a function to sort a list of 10 integer values.
5. Create a list from a given vector of integer values, such that even values are stored at the front of the list and odd values are stored at the end of the list.
*/

#include<iostream>
#include<list>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void f1(){
    list<string> s={"sundar", "aman","raju","komal"};
    list<string>::reverse_iterator rit;
    
    for(rit=s.rbegin();rit!=s.rend();rit++){
        cout<<*rit<<" ";
    }
}

list<int> f2(vector<int> vint){
        list<int> lint(vint.begin(),vint.end());
        return lint;
}

int f3(list<int> &given_list){
    auto it=max_element(given_list.begin(),given_list.end());
    return *it;
}

void f4(list<int> &listL1){
    listL1.sort();
}

list<int> f5(vector<int> &vint){
    list<int> l1;
    vector<int>::iterator it;
    for(it=vint.begin();it!=vint.end();it++){
        if(*it%2==0){
            l1.push_front(*it);
        }else{
            l1.push_back(*it);
        }
    }
    return l1;

}

int main(int argc, char const *argv[])
{
    // f1();
    // vector<string> s1={"sundar", "aman","raju","komal"};
    // vector<int> v1={10,20,30,45,29,35,46,13};
    // list<int> l1=f2(v1);
    // for(auto A:l1){
    //     cout<<A<<" ";
    // }

    // list<int> given_list={10,20,1300,30,45,29,35,46,13};
    // cout<<"max number "<<f3(given_list)<<endl;
    // f4(given_list);
    // for(int X:given_list){
    //     cout<<X<<" ";
    // }
    vector<int> given_vector={10,20,130,30,45,29,35,46,13};
    for(int a:f5(given_vector)){
        cout<<a<<" ";
    }
    return 0;
}

