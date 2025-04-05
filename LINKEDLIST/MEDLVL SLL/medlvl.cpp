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
    if(head == nullptr || head->next == nullptr ){
        return head;
    }
    Node* newHead = reverseLLRecursively(head -> next);
    Node* front = head -> next;
    front -> next = head;
    head -> next = nullptr;
    return newHead;
}


/*
Question 3 
Brute Force Approach 
If there is a cycle in a linked list then when we traverse the list a node will come twice if only if there is a link .
We use hashing to mark every node if a node visited twice there we conclude that there is a cycle.
*/

bool hasCycle(Node* head){
    unordered_map<Node* , int> mpp;
    Node* temp = head;
    while(temp != nullptr){
        if(mpp.find(temp) == mpp.end()) return true;
        mpp[temp] = 1;
        temp = temp -> next;
    }
    return false;
}

/*
Optimal Approach 
Using Tortoise and Hary Algorithm 
If there is a cylce then there is a point come where slow and fast pointers meet .
Look when slow reaches the loop point stops 
*/
bool hasCycleOptimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) return true;
    }
    return false;
}


// Question 4
/*
Brute Force Approach 
We use a stack data structure as in stack data structure the elements are check from bottom to top.
First of all put all the values in stack ds and then traverse over the stack and the given ll if the data matches return true otherwise false.
Time Complexity : O(2*n)
Space Complexity : O(n)
*/
bool isPalindrome(Node* head) {
    stack<int> st;
    Node* temp = head;
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }


    temp = head;
    while(temp != nullptr){
        if(st.top() != temp->data) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}


/*
Optimal Approach 
In optimal Approach we donot use any extra space.
Observation 
If i divide the links in two halfs and in the second half i just reverse the links and from two halfs i check every element of one half matches with the other half it it is then return true otherwise return false.
First I have to divide the two halfs and settle down their heads
so we use the technique of tortise and hary method
For even 
1->2->3->-3->2->1->X
Here when slow is in the 3 place the fast will be in the 5th place so the condition apply to run till fast->next->next != null
For odd
1->2->3->2->1->X
Here slow reaches the middle at 3rd place while fast reaches the 5th place and here the condition apply to run till fast->next != null

Now we get our middle 
it's time to reverse the second half 

reverse(slow->next)

then take a pointer in first half head and another for the second half head and check wheather they are equal or not 


Time Complexity : O(n/2) (for finding middles) + O(n/2) (for reverse) + O(n/2) (for traversing) nearly equal to O(n)
Space Complexity : O(1)
*/
Node* reverse(Node* head) {
    // Using recursive method
    if(head == nullptr || head->next == nullptr) return head;
    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
bool isPalindromeOptimal(Node* head){
    
        Node* fast = head;
        Node* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse the second half 
        Node* newHead = reverse(slow->next);
        Node* first = head;
        Node* second = newHead;
        while(second != nullptr){
            if(first->data != second->data){
                reverse(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverse(newHead);
        return true;
    
}

/*
Question 6
Brute Force Approach 
Take an extra space and there first store odd ones and then even ones .
Time Complexity : O(2*n)
Space Complexity : O(n)
*/
void OddEven(Node* head){
    if(head == nullptr) cout << "0";
        vector<int> arr;
        Node* temp = head;
        while(temp != nullptr && temp->next != nullptr){
            arr.push_back(temp->data);
            temp = temp->next->next;
        }
        if(temp != nullptr) arr.push_back(temp->data);
        temp = head->next;
        while(temp != nullptr && temp->next != nullptr){
            arr.push_back(temp->data);
            temp = temp->next->next;
        }
        if(temp != nullptr) arr.push_back(temp->data);
        temp = head;

        for(int i = 0; i < arr.size(); i++){
            temp->data = arr[i];
            temp = temp->next;
        }
    while(head != nullptr){
        cout << head->data << "-->";
        head = head->next;
    }
}


/*
Optimal Approach
We dont use any extra space here 
Play with the links 
1->2->3->4->5->X

Take two pointer first one odd at first place and second one at the second place as even and move them with two places.
1->3->5  2->4->X 
But we have to link 5->2 to link we have link a node with odd->next because odd is at 5 so at begining store 2 at evenHead one more pointer and then
link odd->next = evenHead

Time Complexity : O(N)
Space Complexity : O(1)
*/

void OddEvenOptimal(Node* head){
    if(head  == nullptr || head->next == nullptr) cout << "O";
    Node* odd = head , *evenHead = odd->next , *even = odd->next;
    
    while(even != nullptr && even->next != nullptr){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;


    while(head != nullptr){
        cout << head->data << "-->";
        head = head->next;
    }
}


/*
Question 6
We have to sort the list
We use extra space and replacement approach

*/
void sortList(Node* head){
Node* temp = head;
if(head == nullptr || head->next == nullptr) cout << head->data;
vector<int> arr; // extra space
while(temp != nullptr){
    arr.push_back(temp->data);
    temp = temp->next;
}
sort(arr.begin(),arr.end());
temp = head;
// replacement
for(int i = 0; i < arr.size(); i++){
    temp->data = arr[i];
    temp = temp->next;
}

// Output
while(head != nullptr){
    cout << head->data <<"-->";
    head = head->next;
}

}


/*
Question 7
By using DummyNode Approach
*/
Node* addList(Node* l1, Node* l2){
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    Node* t1 = l1;
    Node* t2 = l2;
    int carry = 0;
        while(t1 != nullptr || t2 != nullptr){
            int sum = carry;
            if(t1) sum = sum + t1->data;
            if(t2) sum = sum + t2->data;
            Node* newNode = new Node(sum % 10);
            carry = sum/10;
            curr->next = newNode;
            curr = curr->next;
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;

            if(carry){
                Node* newNode = new Node(carry);
                curr->next = newNode;
            }
        }
        while(dummyNode -> next != nullptr){
            cout << dummyNode->next->data <<"-->";
            dummyNode = dummyNode->next;
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
    Node* newHead = reverseLLRecursively(head);
    while(newHead != nullptr){
        cout << newHead -> data << "->";
        newHead = newHead -> next;
    }
    cout << "X";
*/

    /*
    Question 3 
    LinkedList Cycle 
    iven head, the head of a linked list, determine if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

    Return true if there is a cycle in the linked list. Otherwise, return false.
    

    vector<int> arr = {3,2,0,4};
    Node* head = new Node(arr[0]);
    Node* cycle = new Node(arr[1]);
    Node* newnode = head;
    for(int i = 1; i < arr.size(); i++){
       newnode->next = new Node(arr[i]);
       newnode = newnode->next;
    }
    newnode->next = cycle;

    bool isTrue = hasCycle(head);

    cout << isTrue;
    cout << endl;
    // Optimal approach 
    bool isFalse = hasCycleOptimal(head);

    cout << isFalse;

*/

/*
Question 4
Plaindrome LinkedList
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Input: head = [1,2,2,1]
Output: true
Input: head = [1,2]
Output: false

vector<int> arr = {1,2,2,1};
Node* head = new Node(arr[0]);
Node* newnode = head;
for(int i = 1; i < arr.size(); i++){
       newnode->next = new Node(arr[i]);
       newnode = newnode->next;
}
bool ans = isPalindrome(head);
cout << ans;


// Optimal approach 
bool opans = isPalindromeOptimal(head);

cout << opans;

*/
/*
Question 5 
Odd Even Linkedlist
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]


// Brute Force Approach 
vector<int> arr = {1,2,3,4,5};
Node* head = new Node(arr[0]);
Node* newnode = head;
for(int i = 1; i < arr.size(); i++){
       newnode->next = new Node(arr[i]);
       newnode = newnode->next;
}

//OddEven(head);
cout << endl;

// Optimal Approach 
OddEvenOptimal(head);
*/


/*Question 6
Given the head of a linked list, return the list after sorting it in ascending order.
Input: head = [4,2,1,3]
Output: [1,2,3,4]
*/
vector<int> arr = {4,2,1,3};
Node* head = new Node(arr[0]);
Node* newnode = head;
for(int i = 1; i < arr.size(); i++){
       newnode->next = new Node(arr[i]);
       newnode = newnode->next;
}

sortList(head);


/*
Question 7
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/

vector<int> l1= {2,4,5};
vector<int> l2 = {5,6,4};
Node* head1 = new Node(l1[0]);
Node* node1 = head1;
for(int i = 1; i < l1.size(); i++){
    node1->next = new Node(l1[i]);
    node1 = node1->next;
}
Node* head2 = new Node(l2[0]);
Node* node2 = head2;
for(int i = 1; i < l2.size(); i++){
       node2->next = new Node(l2[i]);
       node2 = node2->next;
}
addList(head1,head2);
    return 0;
}