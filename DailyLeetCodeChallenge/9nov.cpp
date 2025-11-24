#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countOperations(int num1, int num2) {
        int k = 0;
        while(num1 != 0 && num2 != 0) {
            k++;
            if(num1 < num2) {
                num2 = num2 - num1;
            }
            else {
                num1 = num1 - num2;
            }

            
        }
        return k;
    }
};
int main() {
    Solution s;
    cout << s.countOperations(2, 3) << endl; // Expected output: 3
    return 0;
}