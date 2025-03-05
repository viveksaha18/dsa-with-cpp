#include<bits/stdc++.h>
using namespace std;

// Question -> Conversion to roman to Int 

void romanToInt(string s){
    unordered_map<char,int> mpp;
    string result;

    mpp['I'] = 1;
    mpp['V'] = 5;
    mpp['X'] = 10;
    mpp['L'] = 50;
    mpp['C'] = 100;
    mpp['D'] = 500;
    mpp['M'] = 1000;

    int n = s.size();

    for(int i = 0; i < n; i++){
        if(i < n - 1 && mpp[s[i]] < mpp[s[i+1]]) result-=mpp[s[i]];
        if(s[i] > s[i + 1] || s[i] == s[i + 1 ]) result+=mpp[s[i]];
    }
    cout<<result;
}
int main(){
    string s = "LVQIII";
    romanToInt(s);
    return 0;
}