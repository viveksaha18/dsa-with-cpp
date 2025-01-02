#include<bits/stdc++.h>
using namespace std;
int main(){
    // declaration of a vector 
    vector<int>v;
    //adding element on either using push-back or emplace-back operations
    v.push_back(2);
    cout<<v[0]<<endl;
    v.emplace_back(5);
    cout<<v[1]<<endl;
    vector<int>v1={1,2,3,4};
    cout<<"Elements present in v1 vector"<<endl;
    for(auto i:v1){
        cout<<i<<endl;
    }
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
        cout<<endl;
    }
// erase 
   v1.erase(v1.begin()+2);
   // Insert function 
   vector<int>v2(3,100);
   v2.insert(v2.begin(),500);
   cout<<"values in v2 vector"<<endl;
   for(auto i:v2){
    cout<<i<<endl;
   }
   cout<<"At the first position "<<endl;
   v2.insert(v2.begin()+1,5);
   for(auto i:v2){
    cout<<i<<endl;
   }
   cout<<v2.size()<<endl;
   cout<<v2.empty();
   v2.clear();
    return 0;
}