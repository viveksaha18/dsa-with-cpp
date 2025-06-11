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


void preorderTraversal(Node* root, vector<int> &ans) {
    if (root == nullptr) {
        return;
    }
    
    // Visit the root node
    ans.push_back(root->data);
    
    // Traverse the left subtree
    preorderTraversal(root->left, ans);
    
    // Traverse the right subtree
    preorderTraversal(root->right, ans);
    
    // Print the result

}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(6);
    root->right->right->right = new Node(9);


    // Preorder Traversal: Root -> Left -> Right
    vector<int> ans;
    preorderTraversal(root,ans);


    cout << "Preorder Traversal: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}