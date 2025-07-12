#include<bits/stdc++.h>
using namespace std;
string decimalToBinary(int n){
    string res = "";
    while(n > 0){
        if(n % 2 == 1) res+='1';
        else res+='0';
        n/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}

int binaryToDecimal(string binary){
    int n =0;
    for(int i = binary.size(); i >= 0; i--){
        if(binary[i] == '1') n = n + pow(2,binary.size() - 1 - i);
    }
    return n;
}
int main(){
    int n = 13;
    string decimal = decimalToBinary(n);
    cout << decimal;
    cout << endl;
    // binary to decimal 
    string binary = "1101";
    int number = binaryToDecimal(binary);
    cout << number;
    return 0;
}