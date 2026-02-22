#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string maximumXor(string s, string t) {
        int cnt0 = 0, cnt1= 0;
        for(char c : t) {
            if(c=='0') cnt0++;
            else cnt1++;
        }
        string res = "";
        for(char c : s) {
            if(c == '0') {
                if(cnt1 > 0) {
                    res+='1';
                    cnt1--;
                }
                else {
                    res+='0';
                    cnt0--;
                }
            }
            else {
                if(cnt0>0) {
                    res+='1';
                    cnt0--;
                }
                else {
                    res+='0';
                    cnt1--;
                }
            }
        }
        return res;
    }
};
int main() {
    Solution s;
    string s1 = "1100";
    string t1 = "1010";
    cout<<s.maximumXor(s1, t1)<<endl;
    return 0;
}