/*
Question link :https://leetcode.com/problems/longest-repeating-character-replacement/description/

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/

#include<bits/stdc++.h>
using namespace std;

/*
Brute Force Approach : Basically here we generate all subarray and look for the valid ones . If our changes are under <= k then its ok.

changes for a subarray will be : length of that subarray - maxFrequency = len - maxFreq


Time Complexity : O(n2) and Space Complexity : O(1)
*/
int longestRepeatingCharacter_BruteForce(string s,int k){
    int maxLen = 0;
    int n = s.size();
    int maxFreq = 0;
    for(int i = 0; i < n; i++){
        map<char,int> mpp;
        for(int j = i; j < n; j++){
            mpp[s[j]]++;
            maxFreq = max(maxFreq,mpp[s[j]]);
            if((j - i + 1) - maxFreq <= k){ // changes which is length of subarray - maximum frequency
                int len = j - i + 1;
                maxLen = max(maxLen,len);
            }
            else break; // Like if exceeds the changes limit so no need to calculate that length of substring as because it is not valid.
        }
    }
    return maxLen;
}

/*
Optimal Approach : Sliding Window Technique
Here we maintain a window and we will keep expanding the window until the changes required to make all characters in the window same is <= k. 
If it exceeds k then we will shrink the window from left side.
*/

int longestRepeatingCharacter_Optimal(string s,int k){
    int maxLen = 0;
    int l = 0 , r = 0;
    int n = s.size();
    int maxFreq = 0;
    map<char,int> mpp;
    while(r < n){
        mpp[s[r]]++;
        maxFreq = max(maxFreq,mpp[s[r]]);
        while((r-l+1) - maxFreq > k){
            mpp[s[l]]--;
            maxFreq = 0;
            for(auto it : mpp) maxFreq = max(maxFreq,it.second);
            l++;
        }
        int len = r - l + 1;
        maxLen = max(maxLen,len);
        r++;
    }
    return maxLen;
}
int main(){
    string s = "AABABBA";
    int k = 1;
    int len = longestRepeatingCharacter_BruteForce(s,k);
    cout << len << endl;
    int maxLen = longestRepeatingCharacter_Optimal(s,k);
    cout << maxLen << endl;
    return 0;
}