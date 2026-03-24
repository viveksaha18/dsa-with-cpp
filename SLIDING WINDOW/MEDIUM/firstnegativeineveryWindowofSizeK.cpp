#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        deque<int> dq;
        int n = arr.size();
        vector<int> v;
        int l = 0,r = 0;
        while(r < n) {
            if(arr[r] < 0) {
                dq.push_back(r);
            }
            if(r-l+1 == k) {
                if(!dq.empty()) {
                    v.push_back(arr[dq.front()]);
                }
                else v.push_back(0);
                if(!dq.empty() && dq.front()==l) {
                    dq.pop_front();
                }
                l++;
            }
            
            r++;
        }
        return v;
    }
};

int main() {
    Solution s;
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    vector<int> ans = s.firstNegInt(arr, k);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}