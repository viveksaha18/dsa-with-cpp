#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int, int> mpp;
        int n = bulbs.size();
        for(int i = 0; i < n; i++) {
            if(mpp.find(bulbs[i]) != mpp.end()) {
                if(mpp[bulbs[i]] == false) {
                    mpp[bulbs[i]]=true;
                }
                else mpp[bulbs[i]]=false;
            }
            else mpp[bulbs[i]]=true;
        }
        vector<int> ans;
        for(auto it : mpp) {
            if(it.second == true) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> bulbs = {1, 2, 3, 2, 1, 4};
    vector<int> ans = s.toggleLightBulbs(bulbs);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}