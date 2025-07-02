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
void postorderTraversal(Node* root, vector<int> &ans) {
    if (root == nullptr) {
        return;
    }
    
    // Traverse the left subtree
    postorderTraversal(root->left, ans);
    
    // Traverse the right subtree
    postorderTraversal(root->right, ans);
    
    // Visit the root node
    ans.push_back(root->data);
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(6);
    root->right->right->right = new Node(9);

    // Postorder Traversal: Left -> Right -> Root
    vector<int> ans;   
    postorderTraversal(root, ans);
    cout << "Postorder Traversal: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout << "Answer of Postorder Traversal is 4 8 5 2 7 9 6 3 1" << endl;
    
    return 0;
}