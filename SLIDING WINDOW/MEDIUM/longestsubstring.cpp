/*
Question : Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
*/

#include<bits/stdc++.h>
using namespace std;


/*
Brute Force Solution : Basically generating all the substrings and check if those were valid or not . 
Time Complexity : O(n2) and Space Complexity : o(256) as characters range from 0 t0 255
*/
int longSubstrwithoutDuplicateCharactersBruteForce(string s){
    int n = s.size();
    int maxLen = INT_MIN;
    for(int i = 0; i < n; i++){
        // For repeating characters we use hashing technique for every string characters 
        vector<int>hashMap(255,0);
        for(int j = i; j < n; j++){
            if(hashMap[s[j]] == 1) break;
            int len = j - i + 1;
            maxLen = max(maxLen,len);
            hashMap[s[j]] = 1;
        }
    }
    return maxLen;
}
/*
Optimal Solution : We use a two pointer appraoch so our string is between l and r . 
We use hashMap for repeating characters and for shrinking the window we particular checks if the characters exists then we can shrink,
as because the string will not be the valid one. 

*/
int longSubstrwithoutDuplicateCharactersOptimal(string s){
    int maxLen = INT_MIN;
    map<char,int>hashMap;
    int left = 0 , right = 0;
    int n = s.size();
    while(right < n){
        if(hashMap.find(s[right]) != hashMap.end()){
            if(hashMap[s[right]] >= left){
                left = hashMap[s[right]] + 1;
            }
        }
        int len = right - left + 1;
        maxLen = max(maxLen,len);
        hashMap[s[right]] = right;
        right++;
    }
    return maxLen;
}
int main(){

    string s = "cabdzabcd";
    int length = longSubstrwithoutDuplicateCharactersBruteForce(s); // Brute force solution 
    cout << length << endl;
    int maxLen = longSubstrwithoutDuplicateCharactersOptimal(s); // Optimal solution 
    cout << maxLen << endl;
    return 0;
}