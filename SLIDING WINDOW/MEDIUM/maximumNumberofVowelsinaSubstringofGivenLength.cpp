#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isVowel(char c) {
    if(c =='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}
    int maxVowels(string s, int k) {
        int n = s.size();
        int r = 0, l = 0, maxCnt = INT_MIN, currCnt = 0;
        while(r < n) {
            if(isVowel(s[r])) {
                currCnt += 1;
            }
            while(r-l+1 > k) {
                if(isVowel(s[l])) {
                    currCnt-=1;
                }
                l++;
            }
            if(r-l+1 == k) {
                maxCnt = max(currCnt, maxCnt);
            }
            r++;
        }
        return maxCnt;
    }
};
int main() {
    Solution s;
    string str = "abciiidef";
    int k = 3;
    cout<<s.maxVowels(str, k);
    return 0;
}