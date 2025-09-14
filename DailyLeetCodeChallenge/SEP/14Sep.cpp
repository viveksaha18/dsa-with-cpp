#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/vowel-spellchecker/"
class Solution {
public:
unordered_set<string> exactSet;
unordered_map<string, string> caseMp;
unordered_map<string, string> vowelMp;
string to_Lower(string s) {
    string r;
    for(char c : s) {
        r += tolower(c);
    }
    return r;
}
string replaceVowel(string s) {
    string r = s;
    for(char &c : r) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            c = '*';
        }
    }
    return r;
}
string check(string query) {
    if(exactSet.find(query) != exactSet.end()) {
        return query;
    }
    string lowerCase = to_Lower(query);
    if(caseMp.find(lowerCase) != caseMp.end()) {
        return caseMp[lowerCase];
    }
    string vowelCase = replaceVowel(lowerCase);
    if(vowelMp.find(vowelCase) != vowelMp.end()) {
        return vowelMp[vowelCase];
    }
    return "";
}
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactSet.clear();
        caseMp.clear();
        vowelMp.clear();
        for(string &word : wordlist) {
            exactSet.insert(word);
            string lowerCase = to_Lower(word);
            if(caseMp.find(lowerCase) == caseMp.end()) {
                caseMp[lowerCase] = word;
            }
            string vowelCase = replaceVowel(lowerCase);
            if(vowelMp.find(vowelCase) == vowelMp.end()) {
                vowelMp[vowelCase] = word;
            }
        }
        vector<string> res;
        for(string &query : queries) {
            res.push_back(check(query));
        }
        return res;
    }
};
int main() {
    vector<string> wordlist = {"KiTe","kite","hare","Hare"};
    vector<string> queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    Solution s;
    vector<string> ans = s.spellchecker(wordlist, queries);
    for(string &s : ans) {
        cout << s << " ";
    }
    return 0;
}