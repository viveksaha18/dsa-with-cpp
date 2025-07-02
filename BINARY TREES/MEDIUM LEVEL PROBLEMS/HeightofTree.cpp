#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node (int val){
        data = val;
        left = right = nullptr;
    }
};  

// Time Complexity : O(N) and Space Complexity : O(N)
int heightofTree(Node* node){
    if(node == nullptr) return 0;

    int lh = heightofTree(node->left); // height of left tree
    int rh = heightofTree(node->right); // height of right tree

    return 1 +  max(lh,rh);
}
int main(){
    /*Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->right->left->left = new Node(7);
    root->right->right = new Node(5);*/

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int height_of_BT = heightofTree(root);
    cout << height_of_BT << endl;
    return 0;
}