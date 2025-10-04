#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/water-bottles/"
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = 0;
        while(numBottles >= numExchange) {
            consumed += numExchange;
            numBottles -= numExchange;
            numBottles += 1;
        }
        return consumed+numBottles;
    }
};
int main() {
    Solution s;
    int numBottles = 9, numExchange = 3;
    cout << s.numWaterBottles(numBottles, numExchange);
    return 0;
}