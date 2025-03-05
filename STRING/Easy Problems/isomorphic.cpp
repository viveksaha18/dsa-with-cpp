#include<bits/stdc++.h>
using namespace std;

// Question - > Two strings s and t are isomorphic if the characteres in s can be replaced to get t
void isomorphic(string s , string t){
    // if two strings have different length they never become  isomorphic 
    if(s.size() != t.size()) cout<<"False";
    int n = s.size();
    for(int i = 0; i < n; i++){
        for(int j = i +1 ; j < n; j++){
            if(s[i] == s[j] && t[i] != t[j]) cout<<"False";
            if(t[i] == t[j] && s[i] != s[j]) cout<<"False";
        }
    }
    cout<<"True";
}
int main(){
    string s = "egg";
    string t = "add";
    isomorphic(s,t);
    return 0;
}