//Everything stores in sorted order and contains unique 
#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int>s;
    s.insert(1);//{1}
    s.insert(2);//{1,2}
    s.insert(2); //{1,2}
    s.insert(3); //{1,2,3}
    s.insert(5); //{1,2,3,5}
    s.insert(4); //{1,2,3,4,5}
    for(auto i:s){
        cout<<i<<endl;
    }
    auto it=s.find(3);
    cout<<*(it);
    s.erase(4);
    multiset<int>m;
    // stores everything in sorted order but not the unique elem
    m.insert(2);
    m.insert(2);
    m.insert(2);
    auto it=m.count(1);
    m.erase(*(it));
    m.erase(m.find(1));
    return 0;
}