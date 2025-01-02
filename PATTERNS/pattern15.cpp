#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the numbers of rows : "<<endl;
    cin>>n;
     char ch='A'; // Initialize outside because want that character to be print once 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<ch<<" ";
        }
        
        ch++;
        cout<<endl;
        
    }
    return 0;
}