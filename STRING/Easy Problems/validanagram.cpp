#include<bits/stdc++.h>
using namespace std;

// Question Valid Anagram 
// A string s can be valid anagram if we rearrange the characters in strings s and gives the string t like if consider s as listen and t
// as silent if we rearrange listen it will give silent which is string t and then we called them as anagram.

// Approach : sort the two strings and after sorting if they are equal then return true otherwise false.

void validAnagram(string s , string t){
    // Sort the two strings 
    sort(s.begin() , s.end());
    sort(t.begin() , t.end());

    // compare

    if(s == t) cout<<"True";
    else cout<<"False";
}
int main(){
    string s = "listen";
    string t = "silent";

    validAnagram(s,t);
    return 0;
}