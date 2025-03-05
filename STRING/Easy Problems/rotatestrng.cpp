#include<bits/stdc++.h>
using namespace std;
// Question -> Rotate the string s if you get goal then return true otherwise false.

bool rotateString(string s,string goal){
    for(int i = 0; i < s.size(); i++){
        char firstChar = s[0];

        s.erase(s.begin());
        s.push_back(firstChar);

        if(s == goal ) return true;
    }
    return false;
}
int main(){
    string s = "abcde";
    string goal = "cdeab";

    int result = rotateString(s,goal);
    cout<<result;
    return 0;
}