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
bool searchLL(Node* head , int key){
    Node* mover = head;
    while(mover != NULL){
        if(mover->data == key){
            return true;
        }
        mover = mover->next;
    }
    return false;
}
int main(){
    vector<int> arr = {1,2,3,4};
    // I have to search 3 
    int key = 3;

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    int result = searchLL(head,key);
    cout<<result; // If it finds the key it should print 1 otherwise it should print 0
    return 0;
}