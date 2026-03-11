#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

 // Intuition is just like
 // path of p and path of q store in vector
 // and then go with the common lowest node
bool findPath(TreeNode* root, TreeNode* tar, vector<TreeNode*>& path) {
    if(root == nullptr) return false;
    path.push_back(root);
    if(root->val == tar->val) {
        return true;
    }
    if(tar->val < root->val) {
        return findPath(root->left, tar, path);
    }
    else return findPath(root->right, tar, path);
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        findPath(root, p, pathP);
        findPath(root, q, pathQ);
        TreeNode* ans = nullptr;
        int i = 0;
        while(i < pathP.size() && i < pathQ.size()) {
            if(pathP[i]==pathQ[i]) {
                ans = pathP[i];
            }
            else break;
            i++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    TreeNode* p = root->left; // 2
    TreeNode* q = root->right; // 8
    cout << s.lowestCommonAncestor(root, p, q)->val << endl; // 6
    return 0;
}