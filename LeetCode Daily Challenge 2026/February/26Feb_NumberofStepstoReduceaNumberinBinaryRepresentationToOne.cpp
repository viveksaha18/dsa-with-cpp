#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void divideByTwo(string& s) {
    s.pop_back();
}
void addOne(string& s) {
    int i = s.size();
    i=i-1;
    while(i >= 0 && s[i]=='1') {
        s[i]='0';
        i--;
    }
    if(i<0) {
        s='1'+s;
    }
    else{
        s[i]='1';
    }
}
    int numSteps(string s) {
        int n = s.size();
        int nofOperations=0;
        while(s.size() > 1) {
            n=s.size();
            if(s[n-1]=='0') {
                divideByTwo(s);
            }
            else{
                addOne(s);
            }
            nofOperations++;
        }
        return nofOperations;
    }
};
int main() {
    Solution s;
    string s1 = "1101";
    int ans = s.numSteps(s1);
    cout << ans;
    return 0;
}