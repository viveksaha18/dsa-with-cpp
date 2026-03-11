#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int mask = 1;
        while(mask <= n) {
            mask=mask<<1;
        }
        mask = mask-1;
        return mask^n;
    }
};
int main() {
    Solution s;
    cout << s.bitwiseComplement(5) << endl; 
    return 0;
}