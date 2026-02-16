#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isPalindrome(int i , int j , string& str) {
   
    while (i  < j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}
    string longestPalindrome(string s) {
        if(s.size() == 1){
            return s;
        }
        int start = 0 , max_len = 0;
        
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(isPalindrome(i,j,s)){
                    if(j - i + 1 >= max_len){
                        max_len = j - i + 1;
                        start = i;
                    }
                    
                    
                }
            }
        }
        return s.substr(start,max_len);
    }
};
int main() {
    Solution s;
    string str = "babad";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}