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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr) {
            targetSum-=root->val;
            if(targetSum == 0) return true;
            else return false;
        }
        //if(targetSum < 0) return false;
        if(root->left != nullptr) {
            if(hasPathSum(root->left, targetSum-root->val)) {
                return true;
            }
        }
        if(root->right != nullptr) {
            if(hasPathSum(root->right, targetSum-root->val)) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    Solution sol;
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
    bool result = sol.hasPathSum(root, targetSum);
    cout << (result ? "True" : "False") << endl;
    return 0;
}