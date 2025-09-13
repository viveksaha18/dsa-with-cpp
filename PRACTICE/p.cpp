#include<bits/stdc++.h>
using namespace std;
/* Question:
Given an array of integers, return the index of the first unique element (element that appears exactly once). If no unique element exists, return -1.

Example:
Input: [4, 5, 1, 2, 1, 2, 5]
Output: 0 (since 4 is the first unique element).*/
int main() {
    int n;
    cin >> n;
    int arr[n];
    int cnt = 0;
    bool flag = false;
    int idx = 0;
    //Input: [4, 5, 1, 2, 1, 2, 5]
    for(int i = 0; i < n; i++) cin >> arr[i];

    /* Brute Force 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                cnt++;
            }
        }
        if(cnt == 1) {
            idx = i;
            flag = true;
            break;
        }
    }
    if(flag) cout << idx;
    */

    vector<int> hashArr(n, 0);
    for(int i = 0; i < n; i++) {
        hashArr[arr[i]]++;
    }
     idx = 0;
    for(int i = 0; i < n; i++) {
        if(hashArr[i] == 1) {
            idx = i;
        }
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] == idx) {
            cout << i;
            break;
        }
    }
    
    return 0;
}