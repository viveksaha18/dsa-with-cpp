#include<bits/stdc++.h>
using namespace std;
// gfg problem link: https://practice.geeksforgeeks.org/problems/count-occurence-of-anagrams5839/1
// User function template for C++
class Solution {
  public:
bool allZeros(unordered_map<char, int>& mpp) {
    for(auto it : mpp) {
        if(it.second != 0) return false;
    }
    return true;
}
    int search(string &pat, string &txt) {
        // code here
        int k = pat.size();
        int n = txt.size();
        
        unordered_map<char, int> mpp;
        for(int x : pat) {
            mpp[x]++;
        }
        
        int j = 0, i = 0, ans = 0;
        while(j < n) {
            mpp[txt[j]]--;
            if(j-i+1 == k) {
                if(allZeros(mpp)) {
                    ans++;
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
    string txt = "forxxorfxdofr";
    string pat = "for";
    cout << s.search(pat, txt);
    return 0;
}
