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
bool dfs(TreeNode* root, long long minVal, long long maxVal) {
    if(root == nullptr) return true;
    if(root->val <= minVal || root->val >= maxVal) return false;
    bool left = dfs(root->left, minVal, root->val);
    bool right = dfs(root->right, root->val, maxVal);
    return left && right;
}
    bool isValidBST(TreeNode* root) {
        // range -infinity to +infinity
        // left -infiniy to root 
        // right root to +infinity
        long long minVal = LLONG_MIN;
        long long maxVal = LLONG_MAX;
        return dfs(root, minVal, maxVal);
    }
};
int main() {
    Solution s;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << s.isValidBST(root) << endl; // Output: 1 (true)
    return 0;
}