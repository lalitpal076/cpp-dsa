#include<iostream>
#include<set>
#include<unordered_set>

#include<string>

using namespace std;

void f1(){
    set<int> s1={6,10,20,15};
    for(auto item:s1){
        cout<<item<<" ";
    }
    cout<<endl;
    set<int>::iterator it;
    for(it=s1.begin();it!=s1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

}

class Student{
    private:
        int rollno;
        string name;
    public:
        Student(int r,string name):rollno(r),name(name){}
        void showStudent(){
            cout<<rollno<<" "<<name<<endl;
        }
        bool operator<(const Student &st)const{
            return this->rollno<st.rollno;
        }
};

void f2()
{
    set<Student> st={{10,"Arjun"},{11,"sandeep"},{12,"radha"},{13,"aditya"},{14,"janvi"},{15,"Roshni"}};
    for(auto item:st){ 
        item.showStudent();
    }
}

//if we want to allow duplicate in set the we have to use multiset class
//multiset<>
void f3(){
    multiset<int> mst={10,20,4,40,4,35,10};
    for(auto item:mst){
        cout<<item<<" ";
    }
}

//unordered set: data doesn't maintain order like set, 
//unordered set: not allowed duplicate values
void f4(){
    unordered_set<int>ust={10,20,40,10,35};
    for(auto item:ust){
        cout<<item<<" ";
    }

}

//unordered multiset: data doesn't maintain order like set, 
//unordered multiset: duplicate values allowed
void f5(){
    unordered_multiset<int>ust={10,20,40,10,35};
    for(auto item:ust){
        cout<<item<<" ";
    }

}

int main()
{
    f5();
    return 0;
}
