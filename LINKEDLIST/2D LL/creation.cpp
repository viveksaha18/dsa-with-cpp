#include<bits/stdc++.h>
using namespace std;

class Node{
    public : 
    int data;
    Node* next;
    Node* prev;
    Node(int data1 , Node* next1, Node* prev1){
        data = data1;
        next =  next1;
        prev = prev1;
    }

    Node(){
        prev = NULL; 
        data = 0; 
        next = NULL;
    }
    Node(int data1){
        prev = NULL;
        data = data1;
        next = NULL;
    }
};

// Representing the 2d linked list from the array elements
int main(){
    vector<int> arr = {1,2,3,4};

    Node* head = new Node(arr[0]);
    Node* temp = head;
    temp->prev = NULL;

    for(int i = 1; i < arr.size(); i++){
        Node* newnode = new Node(arr[i]);
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }

    while(head  != NULL){
        cout<<head->data;
        head = head->next;
    }
    return 0;
}