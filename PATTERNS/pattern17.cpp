#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the numbers of rows : "<<endl;
    cin>>n;
    int initialspace=0;
    // upper part
    for(int i=0;i<n;i++){
        // stars 
        for(int j=1;j<=(n-i);j++){
            cout<<"*";
        }
        // spaces 
        for( int j=0;j<initialspace;j++){
            cout<<" ";
        }
        // stars 
        for(int j=1;j<=(n-i);j++){
            cout<<"*";
        }
         initialspace+=2;
         cout<<endl;
    }
    initialspace=8;
    for(int i=0;i<n;i++){
        // stars 
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        // spaces 
        for(int j=0;j<initialspace;j++){
            cout<<" ";
        }
        // stars 
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        initialspace-=2;
        cout<<endl;
    }
      return 0;
}