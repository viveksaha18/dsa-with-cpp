#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s = s+s;
        string s1 = "";
        string s2 = "";
        for(int i = 0;  i < 2*n; i++) {
            if(i%2 == 0) {
                s1+='0';
                s2+='1';
            }
            else {
                s1+='1';
                s2+='0';
            }
        }
        int i = 0;
        int j = 0;
        int f1 = 0;
        int f2 = 0;
        int result = INT_MAX;
        while(j < 2*n) {
            if(s[j] != s1[j]) {
                f1++;
            }
            if(s[j] != s2[j]) {
                f2++;
            }
            if(j-i+1 > n) {
                if(s[i] != s1[i]) {
                    f1--;
                }
                if(s[i] != s2[i]) {
                    f2--;
                }
                i++;
            }
            if(j-i+1 == n) {
                result = min(result, min(f1, f2));
            }
            j++;
        }
        return result;
    }
};
int main() {
    Solution s;
    string str = "111000";
    cout << s.minFlips(str) << endl;
    return 0;
}