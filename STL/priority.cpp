#include<bits/stdc++.h>
using namespace std;
int main(){
    // Maximum Heap
    priority_queue<int>pq;
    pq.push(4);
    pq.push(2);
    pq.push(1);
    cout<<pq.top()<<endl;// prints 4
    // Minimum Heap
    priority_queue<int,vector<int>,greater<int>>p;
    p.push(5);
    p.push(2);
    p.push(8);
    p.push(10);
    cout<<p.top()<<endl;// prints 2
    return 0;
}