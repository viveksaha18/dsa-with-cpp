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
int sum = 0;
void dfs(TreeNode* root) {
    if(root == nullptr) return;
    if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
        sum+=root->left->val;
    }
    dfs(root->left);
    dfs(root->right);
}
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return sum;
    }
};
int main() {
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << sol.sumOfLeftLeaves(root) << endl; // Output: 24
    return 0;
}