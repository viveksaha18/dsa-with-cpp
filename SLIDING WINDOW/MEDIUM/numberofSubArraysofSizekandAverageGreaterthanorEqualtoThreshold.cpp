#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int currSum = 0, n = arr.size(), r = 0, l = 0, ans = 0;
        while(r < n) {
            currSum += arr[r];
            while(r-l+1 > k) {
                currSum -= arr[l];
                l++;
            }
            if(r-l+1 == k) {
                if(currSum/k >= threshold) {
                    ans+=1;
                }
            }
            r++;
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> arr = {2,2,2,2,5,5,5,8};
    int k = 3, threshold = 4;
    cout<<s.numOfSubarrays(arr, k, threshold);
    return 0;
}