#include<bits/stdc++.h>
using namespace std;

// For the all the characters 
int allchar()
{
    string s;
    cout<<"Enter the string : "<<endl;
    cin>>s;
    int hash[256]={0};
    // pre compute
    for(int i=0;i<s.size();i++){
        hash[s[i]]++;
    }
    int q;
    cout<<"Enter the number of queries : "<<endl;
    cin>>q;
    while(q--){
        char ch;
        cout<<"Enter the character :"<<endl;
        cin>>ch;
        // fetching
        cout<<"The frequency of the given character is : " <<hash[ch]<<endl;
    }
    return 0;
}


// For the lower case 
int lowercase()
{
string s;
    cout<<"Enter the string :"<<endl;
    cin>>s;
    int hash[26]={0};  // for lower case 
    // precomputing 
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    int q;
    cout<<"Enter the numbers of quries :"<<endl;
    cin>>q;
    while(q--){
        char ch;
        cout<<"Enter the character :"<<endl;
        cin>>ch;
        // fetching
        cout<<"The number of repetation is : " <<hash[ch-'a']<<endl;
    }
    return 0;
}
int main(){

   allchar();
   // The function for all the characters 
   lowercase();
   // The fucntion for the lower case

   // For the uppercase the logic  is hash[s[i]-'A'] for pre compute and for fetching is hash[ch - 'A']
    return 0;
}