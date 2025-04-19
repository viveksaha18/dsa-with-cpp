#include<bits/stdc++.h>
using namespace std;

// IN backtracking the last one is executed first.

void printNum(int n , int i ){
    if(i > n){
        return ;
    }
    printNum(n,i+1);
    cout << i;
}
int main(){

    // print number from  n to 1

    int n = 4;
    printNum(n,1);
    return 0;
}