/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<int> ans;
int largestValue(vector<int>& level) {
    int maxi = INT_MIN;
    for(int i = 0; i < level.size(); i++) {
        maxi = max(maxi, level[i]);
    }
    return maxi;
}
void bfs(TreeNode* node) {
    queue<TreeNode*> q;
    q.push(node);
    while(!q.empty()) {
        int s = q.size();
        vector<int> level;
        for(int i = 0; i < s; i++) {
            TreeNode* newNode = q.front();
            q.pop();
            if(newNode->left != nullptr) q.push(newNode->left);
            if(newNode->right != nullptr) q.push(newNode->right);
            level.push_back(newNode->val);
        }
        int lVal = largestValue(level);
        ans.push_back(lVal);
    } 
}

    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return {};
        bfs(root);
        return ans;
    }
};