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
// Question 1 --> Converting array to linkedlist 
void convertAll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    if(arr.empty()) cout<<"List is Empty";
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    //Printing the array as linked list 
    mover = head;
    while(mover != NULL){
        cout<<"["<<mover->data<<"|"<<mover->next<<"]"<<"--->";
        mover=mover->next;
    }

}
int main(){
    
    
    vector<int> arr = {1,2,4,5,7}; 
    
    convertAll(arr);
    

    
    return 0;
}