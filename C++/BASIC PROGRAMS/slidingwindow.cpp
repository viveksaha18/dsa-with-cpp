#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];  // Input in the array
    int opration;
    cout<<"Enter the number of operation : "<<endl;
    cin>>opration;
    int ans=0;
    int left=0;
    int crnt=0;
    for(int right =0;right<n;right++){
        crnt+=arr[right];
        while(crnt>opration){
            crnt-=arr[left];
            left++;
        }
        ans=max(ans,right-left+1);
    }
    cout<<ans<<endl;
    return 0;
}