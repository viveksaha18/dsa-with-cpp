#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n]; // The array
    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<n;i++) cin>>arr[i]; // Taking input in the array
    // precomputing 
    int hash[13]={0};   // Hash array initializes with zero/precomputing 
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }
     

    int q;
    cout<<"Enter the number of queries : "<<endl;
    cin>>q;   // The q represent number of queries
    while(q--){   // Terminates when   q becomes zero
        int number; 
        cout<<"Enter the  number of query :"<<endl;
        cin>>number;
        // fetching 
        cout<<"The frequency of the given number  is : "<<hash[number]<<endl;
        }
        
    return 0;
    
}