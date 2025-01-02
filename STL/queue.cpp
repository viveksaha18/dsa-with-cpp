#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int>q;
    q.push(2);
    q.push(4);
    q.push(8);
    q.back()+=2;
    cout<<q.back()<<endl;//10 {1,2,10}
    q.pop();//{4,10} 
    cout<<q.front()<<endl;// prints 4
    return  0;
}