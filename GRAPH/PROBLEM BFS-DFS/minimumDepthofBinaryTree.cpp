#include<bits/stdc++.h>
using namespace std;

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
int dfs(TreeNode* node, int depth) {
    if(node->left == nullptr && node->right == nullptr) {
        return depth;
    } 
    int left = INT_MAX, right = INT_MAX;
    if(node->left != nullptr) {
        left = dfs(node->left, depth+1);
    }
    if(node->right != nullptr) {
        right = dfs(node->right, depth+1);
    }
    depth =  min(left, right);
    return depth;
}
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return dfs(root, 1);
    }
};
int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int ans = s.minDepth(root);
    cout << ans << endl;
    return 0;
}