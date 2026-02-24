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
vector<string> v;
string str = "";
void f(TreeNode* root) {
    if(root == nullptr) {
        str+="0";
        return;
    }
    if(root->left == nullptr && root->right == nullptr) {
        if(root->val == 1) str+="1";
        else str+="0";
        v.push_back(str);
        return;
    }
    if(root->val == 1) str+="1";    
    else str+="0";
    f(root->left);
    str.pop_back();
    f(root->right);
    str.pop_back();
}
int binaryToDecimal(string s) {
    int n = 0;
    int len = s.size()-1;
    for(int i = len; i >= 0; i--) {
        if(s[i] == '1') {
            n = n + pow(2, len-i);
        }
    }
    return n;
}
    int sumRootToLeaf(TreeNode* root) {
        f(root);
        int sum = 0;
        for(auto it : v) {
            int num = binaryToDecimal(it);
            sum+=num;
        }
        return sum;
    }
};
int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    Solution sol;
    int sum = sol.sumRootToLeaf(root);
    cout << sum;
    return 0;
}