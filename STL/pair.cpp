#include<bits/stdc++.h>
using namespace std;
int main(){
    //pair 
pair<int,int>p={1,3};
cout<<p.first<<"  "<<p.second;
cout<<endl;
pair<int,int>x;
cout<<"Enter the first data in the pair";
cin>>x.first;
cout<<"Enter the second data";
cin>>x.second;
cout<<x.first<<" "<<x.second;
pair<int,pair<int,int>>s;
cout<<"Enter the first number in the pair";
cin>>s.first;
cout<<"Enter the first number in the second pair";
cin>>s.second.first;
cout<<"Enter the second number in the second pair";
cin>>s.second.second;
cout<<endl;
cout<<s.first<<" "<<s.second.first<<" "<<s.second.second;
// create array using pair 
pair<int,int>arr[]={{1,2},{2,5},{4,5}};
cout<<arr[0].first<<" "<<arr[1].second;

// using pair in vectors
vector<pair<int,int>>vec;
vec.push_back({1,3});
cout<<vec[0].first<<endl<<vec[0].second;

vector<int>v1(5,100);
for(auto x:v1){
   
 cout<<x<<endl;
}
cout<<endl;
vector<int>v2(v1);
for(auto i:v2){
    cout<<i<<endl;
}
vector<int>v3(5,20);
vector<int>::iterator it=v3.begin();
it++;
cout<<*(it);
return 0;
}
