#include<bits/stdc++.h>
using namespace std;
void extraVariableSwapping(int a , int b){
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}
int main(){
    int a = 5;
    int b = 6;
    extraVariableSwapping(a,b);
   
    // using xor operator 
    int x = 5;
    int y = 6;
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    cout << x << " " << y << endl;
    return 0;
}