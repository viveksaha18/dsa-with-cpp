#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool allZeros(unordered_map<char, int>& mpp) {
    for(auto it : mpp) {
        if(it.second != 0) return false;
    }
    return true;
}
    vector<int> findAnagrams(string txt, string pat) {
        int k = pat.size();
        int n = txt.size();
        vector<int> ans;
        unordered_map<char, int> mpp;
        for(int x : pat) {
            mpp[x]++;
        }
        
        int j = 0, i = 0;
        while(j < n) {
            mpp[txt[j]]--;
            if(j-i+1 == k) {
                if(allZeros(mpp)) {
                    ans.push_back(i);
                }
                mpp[txt[i]]++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
int main() {
    Solution s;
    string txt = "cbaebabacd";
    string pat = "abc";
    vector<int> result = s.findAnagrams(txt, pat);
    for(int index : result) {
        cout << index << " ";
    }
    return 0;
}