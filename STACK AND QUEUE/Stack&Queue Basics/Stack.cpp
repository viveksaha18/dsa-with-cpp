#include<bits/stdc++.h>
using namespace std;


/*
Stack
It is a data structure that holds certain type of data 

If follows LIFO principle - Last In First Out

Operations push()
pop()
top()
size()

*/
int arr[10];
int topvar = -1; 








void push(int x  ){
    if(topvar >= 10) cout << "Stack is full" << endl;
    topvar = topvar + 1;
    arr[topvar] = x;
}

int pop(){
    if(topvar == -1) cout << "Stack is Empty" << endl;
    int x = arr[topvar];
    
    topvar = topvar - 1;
    return x;
}

int top(){
    if(topvar == -1) cout << " Stack is Empty " << endl;
    return arr[topvar];
}
int main(){

    
    push(10);
    push(29);
    push(23);
    push(22);
    push(48);
    int popele1 =  pop();
    cout << popele1 << endl; 
    int popele2 = pop();
    cout << popele2 << endl;
    int popele3 = pop(); 
    cout << popele3 << endl;
    int topele1 = top();
    cout << topele1 << endl;
    push(34);
    int topele2 = top();
    cout << topele2 << endl;
    return 0;
}