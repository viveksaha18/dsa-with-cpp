#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cout<<"Enter the number of rows : "<<endl;
    cin>>n;
    // first pattern 


    for(int i=0;i<n;i++){
        // print space
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        // print stars
        for(int j=0;j<(2*i+1);j++){
            cout<<"*";
        }
        // print space
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
    

    // second pattern 
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