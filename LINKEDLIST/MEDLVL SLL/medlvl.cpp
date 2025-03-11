#include<bits/stdc++.h>
using namespace std;

// Creation of linkedlist
class Node{
    public:
    int data;
    Node* next;
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


/*
Question 1 : Brute Force Approach 
Time Complexity : O(n) + O(n/2)
Space Complexity : O(1)
*/
Node* middleofSingleLL(Node* head){
    Node* mover = head;
    int len = 0; 
    while(head != nullptr){
        len++;
        head = head->next;
    }
    int mid = len / 2;
    for(int i = 0; i < mid; i++){
        mover = mover->next;
    }
    return mover;
}

/*
Optimal Approach

*/
Node* middleofSingleLLOptimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(){

    /*Question 1 --> Middle of the linkedlist
    Input head = [1,2,3,4,5] return the middle node here is 3
    Output 3 (return the node)
    
    Input head = [1,2,3,4,5,6] 
    Output 4
    */

    vector<int> arr = {1,2,3,4,5,6};
    Node* head = new Node(arr[0]);
    Node* newnode = head;
    for(int i = 1; i < arr.size(); i++){
        newnode->next = new Node(arr[i]);
        newnode = newnode->next;
    }
   
    Node* result = middleofSingleLL(head);
    cout << result->data << endl;


    // Optimal Approach
    Node* ans = middleofSingleLLOptimal(head);
    cout << ans->data;

    return 0;
}