#include<bits/stdc++.h>
using namespace std;

    int main(){
        map<int,int>m; // stores key and value and stores unique key in sorted order 
        m[1]=2;
        m.insert({3,2});
        m.insert({2,5});
        map<pair<int,int>,int>ms;
        ms[{3,5}]=9; // insertion 
        cout<<m[1];
        

        return 0;
    }
