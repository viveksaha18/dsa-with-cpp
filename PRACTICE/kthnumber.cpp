#include<bits/stdc++.h>
using namespace std;
//Given two variables L and R, indicating a range of integers from L to R inclusive, 
//and a number K, the task is to find Kth largest odd number. 
//If K > number of odd numbers in the range L to R then return 0.
bool checkOdd(int i) {
    if(i % 2 == 0) return false;
    return true;
}
int main() {
    int l = -10, r = 10;
    int k = 8;
    vector<int> odds;
    for(int i = l; i <= r; i++) {
        if(checkOdd(i)) {
            odds.push_back(i);
        }
    }
    for(int i = 0; i < odds.size(); i++) {
        cout << odds[i] << " ";
    }
    if(odds.size() < k) return 0;
    for(int i = odds.size()-1; i >= 0; i--) {
        if(odds.size() - i == k) {
            cout << "kth Odd Number is :" << odds[i] << endl;
            break;
        }
        
    }
    return 0;
}