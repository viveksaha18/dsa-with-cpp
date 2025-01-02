#include <bits/stdc++.h>
using namespace std;

// We use user defined datastructure
struct Node{
    public : 
    int data;
    Node* next;

    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }

};

class Node1{
    public : 
    int data;
    Node1* next;
    Node1(int data1 , Node1* next1){
        data = data1;
        next =  next1;
    }
};
int main(){
    vector<int> arr = {2,3,4,6};
    Node* y = new Node(arr[0],nullptr);
    cout<<y->data;

    Node1* x = new Node1(arr[1] , nullptr);
    cout<<x->data;
    return 0;
}