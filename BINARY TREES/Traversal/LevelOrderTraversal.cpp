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
vector<vector<int>> levelOrderTraversal(Node* root){
    vector<vector<int>> ans;
    queue<Node*> q;
    if(root == nullptr) return ans;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++){
            Node* newNode = q.front();
            q.pop();
            if(newNode->left != nullptr){
                q.push(newNode->left);
            }
            if(newNode->right !=  nullptr){
                q.push(newNode->right);
            }
            level.push_back(newNode->data);
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> ans = levelOrderTraversal(root);
    
    // Output of level order traversal 1 2 3 4 5 6 7

    // Output is stored in ans vector 

    for(auto it : ans){
        for(auto x : it){
            cout << x << " ";
        }
    }
    return 0;
}