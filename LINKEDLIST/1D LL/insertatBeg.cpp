#include<bits/stdc++.h>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
    }
};

void insertatBeg(Node* &head , int value){
    Node* newnode = new Node(value);
    if(head == NULL) cout<<"List is empty";
    newnode->next = head;
    head = newnode;
    // printing the list 
    while(head != NULL){
        cout<<"["<<head->data<<"]"<<"-->";
        head = head->next;
    }
    cout<<"[X]";
}
int main(){
    vector<int> arr = {2,3,4,5};
    // Aim is to insert 1 at the begin of the list 
    int data  = 1;
    // Converting array to linkedlist 
    
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    insertatBeg(head ,data);
    return 0;
}