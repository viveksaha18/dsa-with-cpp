#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFreqSum(string s) {
          vector<int> freq(26, 0);

    for (char ch : s) {
        freq[ch - 'a']++;
    }

    string vowels = "aeiou";
    int maxVowelFreq = 0, maxConsonantFreq = 0;

    for (int i = 0; i < 26; ++i) {
        char ch = 'a' + i;
        if (freq[i] > 0) {
            if (vowels.find(ch) != string::npos) {
                maxVowelFreq = max(maxVowelFreq, freq[i]);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, freq[i]);
            }
        }
    }

    return maxVowelFreq + maxConsonantFreq;
    }
};
int main() {
    string str = "success";
    Solution s;
    int ans = s.maxFreqSum(str);
    cout << ans;
    return 0;
}