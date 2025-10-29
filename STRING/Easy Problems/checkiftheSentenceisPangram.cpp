#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/"
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> mpp;
        for(int i = 0; i < sentence.size(); i++) {
            mpp[sentence[i]]++;
        }
        if(mpp.size() == 26) return true;
        return false;
    }
};
int main() {
    Solution s;
    string sentence = "thequickbrownfoxjumpsoverlazylittledog";
    bool isTrue = s.checkIfPangram(sentence);
    if(isTrue == 1) cout << "True";
    else cout << "False";
    return 0;
}