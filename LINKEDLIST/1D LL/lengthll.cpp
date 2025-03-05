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
void lengthofLL(Node* &head){
    if(head == NULL) cout<<"List is empty";
    int cnt = 0;
    while(head != NULL){
        head = head->next;
        cnt++;
    }
    cout<<"The length of the provided linkedlist is : "<<cnt;
}
int main(){
    vector<int> arr = {1,2,3,4};
    // I have to find the length of ll

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    lengthofLL(head);
    return 0;
}