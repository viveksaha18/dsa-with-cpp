#include<bits/stdc++.h>
using namespace std;
/*
Question : Permutation in Strings
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/

class Solution {
public:
bool isFreqSame(int freq1[], int freq2[]) {
    for(int i = 0; i < 26; i++) {
        if(freq1[i] != freq2[i]) return false;
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
        }
        int windSize = s1.size();
        for(int i = 0; i < s2.size(); i++) {
            int windIdx = 0;
            int windFreq[26] = {0};
            int idx = i;
            while(windIdx < windSize && idx < s2.size()) {
                windFreq[s2[idx] - 'a']++;
                windIdx++, idx++;
            }
            if(isFreqSame(freq, windFreq)) return true;
        }
        return false;
    }
};
int main() {
    Solution obj;
    cout << obj.checkInclusion("ab", "eidbaooo") << endl;
    return 0;
}