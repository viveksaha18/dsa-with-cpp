#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/reverse-vowels-of-a-string"
// Time Complexity : O(n) + O(k) + O(n) where k is number of vowels in the string
// Space Complexity : O(k)
class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        string vowels;
        for(char c : s) {
            if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
                vowels.push_back(c);
            }
        }
        reverse(vowels.begin(), vowels.end());
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(j > vowels.size()) break;
            if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') {
                s[i] = vowels[j];
                j++;
            }
        }
        return s;
    }
};

// Optimal Solution 
// Time Complexity : O(n)
// Space Complexity : O(1)
class Solution1 {
public:
bool isVowel(char c) {
      if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' 
        || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
        return false;
}
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0; 
        int j = n - 1;
        while(i < j) {
            if(!isVowel(s[i])) i++;
            else if(!isVowel(s[j])) j--;
            else {
                swap(s[i], s[j]);
                i++, j--;
            }
        }
        return s;
    }
};
int main() {
    string s = "leetcode";
    Solution s1;
    cout << s1.reverseVowels(s) << endl;
    Solution1 s2;
    cout << s2.reverseVowels(s) << endl;
    return 0;
}