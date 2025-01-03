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

void deleteatDesiredPos(Node* &head,Node* &delnode){
    delnode->data = delnode->next->data;
    Node* temp = delnode->next;
    delnode->next = delnode->next->next;
    free(temp);

    while(head != NULL){
        cout<<head->data;
        head = head->next;
    }
}


int main(){
    vector<int> arr = {1,2,4,6}; 
    

    // converting array to linked list
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        mover->next =  new Node(arr[i]);
        mover = mover->next;
    }
    Node* delnode = head->next;

    deleteatDesiredPos(head,delnode);

    return 0;
}