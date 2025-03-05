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

void deleteatEnd(Node* &head){
    if(head == nullptr) cout<<"List is empty";
    Node* mover = head;
    
    while(mover->next->next != NULL){
        mover=mover->next;
    }
    free(mover->next);
    mover->next = nullptr;

    // Printing the ll
    while(head != nullptr){
        cout<<"["<<head->data<<"]"<<"-->";
        head = head->next;
    }

}
int main(){
    vector<int> arr = {1,2,3,4};
    // I have to delete 4 so the arr should contain 1,2,3

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    deleteatEnd(head);
    
    return 0;
}