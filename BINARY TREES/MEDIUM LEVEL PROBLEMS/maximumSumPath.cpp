#include<bits/stdc++.h>
using namespace std;

/*
Question:
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
*/
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int maxSum = INT_MIN;


// Brute Force Approach 
// This approach calculates the maximum sum path by recursively finding the sum of all paths from each node to its descendants.
// Time Complexity: O(N^2) where N is the number of nodes in the tree.
// Space Complexity: O(N) for the recursion stack in the worst case.
int findMaxSum(Node* root) {
    if(root == nullptr) return 0;
    int leftSum = findMaxSum(root->left);
    int rightSum = findMaxSum(root->right);
    return leftSum + rightSum + root->data;
}
void maximumSumPath_BruteForce(Node* root) {

    if(root == nullptr) {
        return ;
    }

    int leftSum = max(0,findMaxSum(root->left));
    int rightSum = max(0,findMaxSum(root->right));
    maxSum = max(maxSum, leftSum + rightSum + root->data);

    maximumSumPath_BruteForce(root->left);
    maximumSumPath_BruteForce(root->right);
}




// Optimal Approach 
// This approach calculates the maximum path sum in a single traversal of the tree.
// Time Complexity: O(N) where N is the number of nodes in the tree.
// Space Complexity: O(H) where H is the height of the tree due to recursion stack
int maximumSumPath_Optimal(Node* root, int& maxSum) {
    if(root == nullptr) return 0;
    int lSum = max(0, maximumSumPath_Optimal(root->left, maxSum));
    int rSum =max(0, maximumSumPath_Optimal(root->right, maxSum));
    maxSum = max(maxSum, lSum + rSum + root->data);
    return root->data + max(lSum, rSum);
}
int main() {
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);


    maximumSumPath_BruteForce(root); // The brute force approach 

    cout << maxSum << endl;
    

    // Optimal one 
    maxSum = INT_MIN; 
 
    maximumSumPath_Optimal(root, maxSum);
    cout << maxSum << endl;

    return 0;
}