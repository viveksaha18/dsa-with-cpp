#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the numbers of rows : "<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        // print number 
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        // print space 
        for(int j=1;j<=(2*(n-i))-1;j++){
            cout<<" ";
        }
        // print number
        for(int j=i;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}