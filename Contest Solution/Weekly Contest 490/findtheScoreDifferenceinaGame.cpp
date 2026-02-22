#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        // initially first active and second inactive 
        // nums[i]]->swap roles
        // everysixth->swap roles
        bool first = true;
        bool second = false;
        int pointsFirst = 0;
        int pointsSecond = 0;
        for(int i = 0; i < nums.size(); i++) {
            int ele = nums[i];
            if(ele % 2 != 0) {
                first = !first;
                second = !second;
            }
            if((i+1) % 6 == 0) {
                first = !first;
                second = !second;
            }
            if(first) pointsFirst+=nums[i];
            else pointsSecond+=nums[i];
        }
        return pointsFirst-pointsSecond;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6};
    cout<<sol.scoreDifference(nums)<<endl;
    return 0;
}