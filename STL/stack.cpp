#include<bits/stdc++.h>
using  namespace std;
int main(){
    stack<int>st;
    st.push(3);
    st.push(5);
    st.push(2);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    stack<int>st1,st2;
    st1.swap(st2);
    // follow lifo rule last in first out

    return 0;
}