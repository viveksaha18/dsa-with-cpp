#include<bits/stdc++.h>
using namespace std;

// Question -> To find out the largest odd number in string 

void findOddNumbers(string s){
    for(int i = n - 1; i >= 0; i--){
        if((s[i] - '0' ) % 2 != 0) cout<< substr(0,i+1);
    }
    cout<<"";

}
int main(){

    string s = "52";
    findOddNumber(s);
    return 0;
}