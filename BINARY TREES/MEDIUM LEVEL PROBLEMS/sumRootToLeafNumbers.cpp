#include <bits/stdc++.h>
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
    long long sum = 0;
    void f(TreeNode *node, long long n) {
        if (node->left == nullptr && node->right == nullptr) {
            n = n * 10;
            n += node->val;
            sum += n;
            return;
        }
        n = n * 10;
        n += node->val;
        if (node->left != nullptr){
            f(node->left, n);
        }
        if (node->right != nullptr) {
            f(node->right, n);
        }
    }
    int sumNumbers(TreeNode *root) {
        f(root, 0);
        return (int)sum;
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << s.sumNumbers(root) << endl;
    return 0;
}