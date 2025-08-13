#include<bits/stdc++.h>
using namespace std;

// recursive one - but here what problems,  
// it always keep on breaking until the base case hits, like if i know a call but at the same time, we not store that and in future calls with same n we have to go till the base case hits which are like extras calls.


int f(int n, vector<int>& dp) {
    
    
}
// Here, time Complexity is O(n) space complexity : O(n) (stack space) + O(n) (array space)
/// @return 
int main() {
    int n = 5;
    vector<int> dp(n + 1, -1);
    //dp[0] = 0, dp[1] = 1;
    cout  << f(n, dp) << endl;


    // for the tabulation form  
    // TC : O(n) SC : O(n) no stack space 
    int x = 5;
    vector<int> dpTabulation(x + 1, -1);
    dpTabulation[0] = 0, dpTabulation[1] = 1;
    for(int i = 2; i <= 5; i++) {
        dpTabulation[i] = dpTabulation[i - 1] + dpTabulation[i - 2];
    }
    cout << dpTabulation[n] << endl;

    int y = 5;
    int prev = 1, prev2 = 0;
    for(int i = 2; i <= y; i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout << prev << endl; // TC : O(n) SC : O(1)
    return 0;
}