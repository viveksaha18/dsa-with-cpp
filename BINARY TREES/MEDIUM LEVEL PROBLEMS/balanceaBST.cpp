#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<int> ans;
void dfs(TreeNode*  node) {
    if(node == nullptr) return;
    if(node != nullptr) {
        ans.push_back(node->val);
    }
    if(node->left != nullptr)  
        dfs(node->left);
    if(node->right != nullptr)
        dfs(node->right);
}
TreeNode* f(int l, int r) {
    if(l > r) return nullptr;
    int mid = (l+r)/2;
    TreeNode* node = new TreeNode();
    node->val = ans[mid];
    node->left = f(l, mid-1);
    node->right = f(mid+1, r);
    return node;
}
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        sort(ans.begin(), ans.end());
        int l = 0, r = ans.size()-1;
        TreeNode* node = f(l, r);
        return node;
    }
};
int main() {
    return 0;
}