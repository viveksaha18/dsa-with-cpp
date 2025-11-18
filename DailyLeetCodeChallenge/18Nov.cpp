#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        while(i < n-1) {
            if(bits[i] == 1) {
                i+=2;
            }
            else i++;
        }
        return i == n-1;
    }
};
int main() {
    Solution sol;
    vector<int> bits = {1,0,0};
    cout << sol.isOneBitCharacter(bits);
    return 0;
}