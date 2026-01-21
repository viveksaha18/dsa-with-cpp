#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;                                       
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
void f(TreeNode* node, int k, vector<int>& temp, vector<vector<int>>& ans) {
    if(node == nullptr) return;
    temp.push_back(node->val);
    k-=node->val;
    if(node->left == nullptr && node->right == nullptr) {
        if(k == 0) {
            ans.push_back(temp);
        }
        temp.pop_back();
        return;
    }

    if(node->left != nullptr) {
        f(node->left, k, temp, ans);
    }
    if(node->right != nullptr) {
        f(node->right, k, temp, ans);
    }
    temp.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // f(node, targetSum, temp, ans)
        vector<int> temp;
        vector<vector<int>> ans;
        f(root, targetSum, temp, ans);
        return ans;
    }
};
int main() {
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    int targetSum = 22;
    vector<vector<int>> ans = s.pathSum(root, targetSum);
    for(auto vec : ans) {
        for(auto val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}