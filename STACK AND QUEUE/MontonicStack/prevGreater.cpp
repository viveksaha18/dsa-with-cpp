#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    int n = nums.size();
    stack<int> st;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        while(st.size() > 0 && nums[i] >= st.top()) {
            st.pop();
        }
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(nums[i]);
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    return 0;
}