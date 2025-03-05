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
void deleteatBeg(Node* &head){
    Node* mover = head;
    head = head->next;
    free(mover);

    // printing the ll
    while(head != nullptr){
        cout<<"["<<head->data<<"]"<<"-->";
        head = head->next;
    }

}
int main(){
    vector<int> arr = {1,2,3,4};
    // I have to delete 1 so the arr should contain 2,3,4

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    deleteatBeg(head);
    return 0;
}