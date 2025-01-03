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


void insertAtEnd(int val , Node* head ){
    Node* newnode = new Node(val);
    Node* mover = head;
    while(mover->next != NULL){
        mover = mover->next;
    }
    mover->next = newnode;
}
void printLL(Node* head){
    if(head == NULL) cout<<"List is empty ";
    while(head != NULL ){
        cout<<"["<<head->data<<"]"<<"-->";
        head = head->next;
    }

}
int main(){
    vector<int> arr = {1,2,3,4,5};

// Creating a linked list with the help of an array 
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    int value = 6; // Element to be inserted at the end 
    insertAtEnd(value , head);
    printLL(head);
    return 0;
}