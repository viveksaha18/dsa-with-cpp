#include <bits/stdc++.h>
using namespace std;
// Problem link :"https://leetcode.com/problems/valid-triangle-number/"
class Solution
{
public:
    int binarySearch(vector<int> &nums, int l, int r, int target)
    {
        int k = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] < target)
            {
                k = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return k;
    }
    int triangleNumber(vector<int> &nums)
    {
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int sum = nums[i] + nums[j];
                int k = binarySearch(nums, j + 1, nums.size() - 1, sum);
                if (k != -1)
                {
                    cnt += k - j;
                }
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 2, 3, 4};
    cout << s.triangleNumber(nums);

    return 0;
}