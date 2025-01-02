#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cout<<"Enter the number of rows : "<<endl;
    cin>>n;
    // outer loop
    for(int i=0;i<n;i++){
        // print space
        for(int j=1;j<=i;j++){
            cout<<" ";
        }
        // print stars
        for(int j=0;j<((2*n-1)-(2*i)); j++){
            cout<<"*";
        }
        // print space
        for(int j=1;j<=i;j++){
            cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}