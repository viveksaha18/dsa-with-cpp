#include<bits/stdc++.h>
using namespace std;
// For the draw back of arrays we use maps for hashing
int hashmap()
{
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];   //  Input in the array 
    
    // The elements are stored in unordered/ unsorted manner 
    unordered_map<int,int>mpp;
  
    // The elements are stored in sorted manner 
    // map<int,int> mpp;

    // pre compute 
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    // maps stored in sorted order 
    for(auto it: mpp){   // iterate in the map
        cout<<it.first<<"->"<<it.second<<endl;
    }

    int q;
    cout<<"Enter the number of queries : "<<endl;
    cin>>q;
    while(q--){
        int number;
        cout<<"Enter the number : "<<endl;
        cin>>number;
        // fetching 
        cout<<"The frequency of the number is : "<<mpp[number]<<endl;
    }
    return 0;
}


// char hashmap
int chrhashmap(){
   
   string s;
   cout<<"Enter the string :"<<endl;
   cin>>s; 
    map<char,int> mpp;
    // pre compute 
    for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
    }

    int q;
    cout<<"Enter the number of queries : "<<endl;
    cin>>q;
    while(q--){
        char ch;
        cout<<"Enter the character  : "<<endl;
        cin>>ch;
        // fetching 
        cout<<"The frequency of the number is : "<<mpp[ch]<<endl;
    }

    return 0;
}
int main(){
   hashmap();
    //chrhashmap(); // char hashmap
    return 0;
}