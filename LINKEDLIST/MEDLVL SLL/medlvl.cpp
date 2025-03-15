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
Use the Tortosie and Hare Method 
Intituition : If x and y are two friends and x moving with d speed and y is moving with a speed of d / 2 , so when the x reaches the destination y is somewhere in the middle for sure.
Time Complexity : O(n / 2)
Space Complexity : O(1)
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


/*
Question 2 
Brute Force Approach 
Use a stack data structure first push everything and then pop it.
Time Complexity : O(2n)
Space Complexity : O(n)
*/
void reverseLLBrute(Node* head){
    stack<int> st;
    Node* temp = head;

    // Push all the elements of linked list in the stack 
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    // Reinitialize the temp
    temp = head;
    //Pop the elements
    while(temp != nullptr){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    while(head != nullptr){
        cout << head->data <<"-->";
        head = head->next;
    }
}


/*
Optimal Approach --> Not use any external data structure which reduce out space complexity 

Intituition --> We have to play with the links 

INPUT 1-> 2-> 3 -> 4-> 5-> X
OUTPUT 5-> 4-> 3-> 2-> 1-> X

What we can do?
 X <-1 <-2 <-3 <-4 <-5  Reverse the links 
How ??
Understand with the example 

[prev]  [temp]--->  my job is to reverse the link [prev] <---[temp] 

so What i can do i can use one more node for not to lose the next [front] [prev] <---[temp]  [front]-->
front = temp -> next;
temp -> next = prev;
go for next node to be connected 
prev = temp 
temp = front 
*/

void reverseLLOptiaml1(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    Node* front = head;

    while(temp != nullptr){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    while(prev != nullptr){
        cout << prev->data <<"-->";
        prev = prev->next;
    }
}


/*
Reccursive Appraoch 
Solve the bigger problem into small small problem 

[Problem Statement]
                |
        [Smaller Problem]
                        |
                    [Smaller Problem]
                                |
                            [Smaller Problem]
                                        |
                                    [Base Case]
*/

Node* reverseLLRecursively(Node* head){
    if(head == nullptr && head->next == nullptr ){
        return head;
    }
}
int main(){

    /*Question 1 --> Middle of the linkedlist
    Input head = [1,2,3,4,5] return the middle node here is 3
    Output 3 (return the node)
    
    Input head = [1,2,3,4,5,6] 
    Output 4
    

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
    */


    /*
    Question 2 --> Reverse a linked list
    Input 1 -> 2 - > 3 -> 4 -> 5 -> X
    Output 5 -> 4 -> 3 -> 2 -> 1-> X
    */
   vector<int> arr = {1,2,3,4,5};
   Node* head = new Node(arr[0]);
   Node* newnode = head;
   for(int i = 1; i < arr.size(); i++){
       newnode->next = new Node(arr[i]);
       newnode = newnode->next;
    }

    //Brute Force Approach 
    //reverseLLBrute(head);
    cout << endl;
    // Optiamal Approach 1  
    //reverseLLOptiaml1(head);

    // Recursive Approach 
    reverseLLRecursively(head);


    return 0;
}