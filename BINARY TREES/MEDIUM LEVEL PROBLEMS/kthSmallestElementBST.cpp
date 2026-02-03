#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};


class Solution {
public:
vector<int> v;
void traversal(TreeNode* node) {
    if(node == nullptr) return;
    v.push_back(node->val);
    traversal(node->left);
    traversal(node->right);
}
    int kthSmallest(TreeNode* root, int k) {
        traversal(root);
        sort(v.begin(), v.end());
        return v[k-1];
    }
};
int main() {
    /*
        Example BST:
              5
             / \
            3   6
           / \
          2   4
         /
        1
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    Solution obj;
    int k = 3;
    cout << "Kth smallest element: " << obj.kthSmallest(root, k) << endl;
    return 0;
}