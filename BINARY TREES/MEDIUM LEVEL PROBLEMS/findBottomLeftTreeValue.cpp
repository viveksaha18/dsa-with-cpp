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
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* current = root;
        queue<TreeNode*> q;
        q.push(current);
        while(!q.empty()) {
            current = q.front();
            q.pop();
            if(current->right != nullptr) {
                q.push(current->right);
            }
            if(current->left != nullptr) {
                q.push(current->left);
            }
        }
        return current->val;
    }
};
int main() {
    Solution sol;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    int result = sol.findBottomLeftValue(root);
    cout << result << endl; // Output: 1
    return 0;
}