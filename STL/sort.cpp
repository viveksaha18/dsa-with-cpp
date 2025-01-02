#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.second<p2.second)
    return true;
    if(p1.second>p2.second)
    return false;
    // they are same
    if(p1.first>p2.first)
    return true;
    else
    return false;
}
int main(){
    int a[5]={2,4,1,3,0};
    sort(a,a+6); // sort in one line 
   for(auto i: a){
    cout<<i<<endl;    
   }
   int k[4]={1,4,2,3};
   sort(a+2,a+4);
   // in vectors sort(v.begin(),v.end())
   // in descending order 
   // sort in my way 
   pair<int,int>p[]={{1,2},{2,1},{4,1}};
   // sort it according to second element 
   // if second element is same , then sort 
   // according to first element but in descending order 
   sort(p,p+3,comp);
   int num=7;
   int cnt=__builtin_popcount(num);// gives the count of 1 when 7 converts into binary
   cout<<cnt;
   long long n=1587871555484;
   int c=__builtin_popcount(c);
   cout<<c<<endl;
   string s="123";
   do{
    cout<<s<<endl;
   }while(next_permutation(s.begin(),s.end()));
   int a1[4]={2,3,4,5};
   int maxi=*max_element(a1,a1+4); // returns the maximum element 
   cout<<maxi<<endl;
    return 0;
}