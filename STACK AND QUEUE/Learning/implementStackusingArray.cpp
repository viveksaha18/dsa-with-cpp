#include<bits/stdc++.h>
using namespace std;
int arr[10]; 
int top = -1;

void pushStack(int x){
    if(top > 9){
        cout <<"Stack is full" << endl;
    }
    else{
        top++;
        arr[top] = x;
    }
}

void popStack(){
    if(top == -1) cout << "Stack is Empty" << endl;
    else{
        cout << "Popped Element:" << arr[top] << endl;
        top--; 
    }
}


void sizeStack(){
    cout << "Size of the stack is:" << top + 1 << endl;
}


void topStack(){
    if(top == -1) cout  << "Stack is Empty" << endl;
    else cout << "Top Element is:" << arr[top] << endl;
}
int main(){
    pushStack(1);
    pushStack(2);
    pushStack(3);
    topStack();
    popStack();
    sizeStack();
    return 0;
}