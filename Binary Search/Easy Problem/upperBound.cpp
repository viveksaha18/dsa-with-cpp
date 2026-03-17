#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int ans = arr.size();
        int l = 0, h = ans-1;
        while(l <= h) {
           int mid = l + (h-l)/2;
           if(arr[mid] > target) {
               ans = mid;
               h=mid-1;
           }
           else l = mid+1;
       }
       return ans;
    }
};
int main() {
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 3;
    cout << s.upperBound(arr, target) << endl;

    return 0;
}