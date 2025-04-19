#include<bits/stdc++.h>
using namespace std;



void getPermutation(vector<int>&arr , int idx , vector<vector<int>>&ans){
    if(idx == arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i = idx ; i < arr.size(); i++){
        swap(arr[idx],arr[i]);
        getPermutation(arr,idx+1,ans);
        swap(arr[idx],arr[i]); // Backtracking
    }
}
int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    getPermutation(arr,0,ans);

    for(auto it : ans){
        for(auto i : it){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}