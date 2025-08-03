#include<bits/stdc++.h>
using namespace std;
/*
Question :
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 
*/
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

bool isSame(Node* p, Node* q) {
    if(p == nullptr && q == nullptr) return true;
    if(p == nullptr || q == nullptr) return false;
    if(p->data == q->data) return isSame(p->left, q->left) && isSame(p->right, q->right);
    return false;
}
int main() {
    // first Nbde
    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);

    // second Node
    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);

    cout << isSame(p, q);

    return 0;
}