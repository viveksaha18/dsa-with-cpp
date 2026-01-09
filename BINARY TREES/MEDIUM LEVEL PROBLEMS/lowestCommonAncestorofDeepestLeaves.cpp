#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
unordered_map<int, int> mpp;
int maxD = 0;
void depth(TreeNode* root, int d) {
    if(root == nullptr) return;
    maxD = max(maxD, d);
    mpp[root->val] = d;
    depth(root->left, d+1);
    depth(root->right, d+1);
}
TreeNode* LCA(TreeNode* root) {
    if(root == nullptr || mpp[root->val] == maxD) return root;
    TreeNode* l = LCA(root->left);
    TreeNode* r = LCA(root->right);
    if(l != nullptr && r != nullptr) return root;
    if(l != nullptr) return l;
    return r;
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root, 0);
        return LCA(root);
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);   
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    TreeNode *ans = s.lcaDeepestLeaves(root);
    cout << ans->val << endl; // Output the value of the subtree root
    return 0;
}