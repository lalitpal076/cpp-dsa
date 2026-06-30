// ---------------- Vector More Functions ----------------

/*
1. Write a function to delete all the values from the first negative value occurred in a given vector of integers.
2. Create a vector object with three integer values. Now insert 25 three times just before the last element (call insert method only once).
3. Create a vector of vectors of integer values from a given vector of integers such that each vector inside a vector contains sorted integer elements that appear in the given vector in consecutive places.
    For example, given vector has {2,4,10,5,7,6,15,20,3,9} values then the resulting vector contains 4 vectors:
    {2,4,10}, {5,7}, {6,15,20}, {3,9}

4. Given vector has integer values stored in it. Write a function to delete all the prime numbers from the vector.
5. Create a vector from the given vector of three vectors of integers, such that take first 3 values from the first vector, last two values of the second vector and all the elements of third vector.
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> f1(vector<int> vint){
    vector<int>::iterator it;
    it=vint.begin();
    while (*it>0 && it!=vint.end())
    {
        it++;
    }
    if(*it<0){
        vint.erase(it,vint.end());
    }
    return vint;    
}

void f2(){
    vector<int> vint={1, 4, 7};
    vector<int>::iterator it;
    it=vint.end();
    vint.insert(it-1,3,25);
    for(auto X:vint){
        cout<<X<<" ";
    }
}

void f3(){
    vector<int> given_vector={2,4,10,5,7,6,15,20,3,9};
    vector<vector<int>> targetVctr;
    vector<int>temp;
    int i=0,s,e,j=0;
    while (i<given_vector.size()-1)
    {
        s=i;
        while(i<given_vector.size()-1 && given_vector.at(i)< given_vector.at(i+1)){
            i++;
        }
        e=++i;
        temp.insert(temp.begin(),given_vector.begin()+s,given_vector.begin()+e);
        targetVctr.insert(targetVctr.begin()+j,temp);
        temp.clear();
        j++;
    }

    for(auto X:targetVctr){
        cout<<"{";
        for (auto Y:X)
        {
           cout<<Y<<" "; 
        }
        cout<<"}";
    }
    

}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i*i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
void f4(){
    vector<int> vcc={10,11,13,15,16,18,20,24,25};
    vector<int>::iterator it;
    for(it= vcc.begin();it!=vcc.end();){
        if(isPrime(*(it)))
            it=vcc.erase(it);
        else {
            it++;
        }
        
    }
    for(auto X:vcc){
        cout<<X<<" ";
    }
}

void f5(){
    vector<vector<int>> given_vector={   
                                    {1, 2, 3, 4},     
                                    {10, 20, 30},     
                                    {100, 200, 300}
                                    };
    vector<int> destination;
    destination.insert(destination.end(),given_vector.at(0).begin(),given_vector.at(0).begin()+3);
    destination.insert(destination.end(),given_vector.at(1).end()-2,given_vector.at(1).end());
    destination.insert(destination.end(),given_vector.at(2).begin(),given_vector.at(2).end());

    for(auto a:destination)
        cout<<a<<" ";
}


int main()
{
    // vector<int> vint={1, 4, 7, 10, 12, -3, -6, -9, -11, -15, 5, 8, 13, 16, 20};
    // for(auto X:vint){
    //     cout<<X<<" ";
    // }
    // cout<<endl;
    // for(auto X:f1(vint)){
    //     cout<<X<<" ";
    // }

    f5();
    return 0;
}
