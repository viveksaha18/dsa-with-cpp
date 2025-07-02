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

int heightofTree(Node* node){
    if(node == nullptr) return 0;

    int lh = heightofTree(node->left); // height of left tree
    if(lh == -1) return -1;
    int rh = heightofTree(node->right); // height of right tree
    if(rh == -1) return -1;

    if(abs(lh - rh ) > 1) return -1;

    return 1 +  max(lh,rh);
}

bool balancedTree(Node* root){
    bool ans = heightofTree(root) != -1;
    cout << ans << endl;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->right->left->left = new Node(7);
    root->right->right = new Node(5);

    balancedTree(root);
    return 0;
}