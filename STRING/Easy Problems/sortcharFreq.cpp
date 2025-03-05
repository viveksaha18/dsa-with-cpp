#include<bits/stdc++.h>
using namespace std;
// Question -> Sort in decreasing order based on the frequency of characters . 

// string s = string(5,'a') output aaaaa

void frequency_Sort(string s ){
    unordered_map<char,int> mpp;
    int highfreq = INT_MIN;
    string ans;
    for(char ch : s){
        mpp[ch]++;
        highfreq = max(highfreq , mpp[ch]);
    }

    while(highfreq > 0){
        for(auto it : mpp){
            if(it.second == highfreq){
                ans+=string(highfreq , it.first);
            }
        }
        highfreq--;
    }
    cout<<ans;
}
int main(){
    string s = "tree";

    frequency_Sort(s);
    return 0;
}