#include<bits/stdc++.h>
using namespace std;

/*
Question : https://www.naukri.com/code360/problems/next-smaller-element_1112581
Given an array you have to find the next smaller element of every index if not present then put -1 and return the ans.
Example :
arr[] = [2, 1, 4, 3]
Output : [1, -1, 3, -1]
*/


// Brute Force Approach : Time Complexity : O(n2) and Space Complexity : O(1)
vector<int> nextSmaller_Brute(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++) {
        int smaller_Element = arr[i];
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < smaller_Element) {
                ans[i] = arr[j];
            }
        }
    }
    return ans;
}


// Optimal Approach : Time Complexity : O(n) and Space Complexity : O(2n)

vector<int> nextSmaller_Optimal(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--) {
        // remove all the greater elements from the stack 
        while(!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return ans;
}
int main() {
    vector<int> arr = {2, 1, 4, 3};
    vector<int> brute_Ans = nextSmaller_Brute(arr);
    for(auto it : brute_Ans) {
        cout << it << " ";
    }
    cout << endl;
    vector<int> optimal_Ans = nextSmaller_Optimal(arr);
    for(auto it : optimal_Ans) {
        cout << it << " ";
    }
    return 0;
}