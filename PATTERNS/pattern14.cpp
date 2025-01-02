#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the numbers of rows : "<<endl;
    cin>>n;
    for(int i=n;i>0;i--){
        char ch='A';
        for(int j=i;j>0;j--){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
    return 0;
}