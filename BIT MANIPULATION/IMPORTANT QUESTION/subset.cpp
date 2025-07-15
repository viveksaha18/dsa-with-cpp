#include<bits/stdc++.h>
using namespace std;



/*
Question:
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/



// Time Complexity: O(2^n * n) where n is the size of the input array
// Space Complexity: O(2^n * n) for storing all subsets
vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> ans;
    int n = nums.size();
    int totalSubsets = 1 << n; // 2^n subsets
    for(int i = 0; i < totalSubsets; i++){
        vector<int> subset;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                subset.push_back(nums[j]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}
int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for(auto subset : ans){
        cout << "[";
        for(int num : subset){
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}