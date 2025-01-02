#include<bits/stdc++.h>
using namespace std;
// Time Complexity : O(n) and Space complexity : O(1)
void ls(vector<int> &arr , int target){
    int ans = -1;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i]  ==  target){
            ans = i;
            break;
        }
    }
    if(ans == -1){
        cout<<"Element is not present " <<endl;
    }
    else{
        cout<<"The element is present at : "<< ans << " index " <<endl;
    }
}
int main(){
    // performing linear search 
    vector<int> arr = {1,2,5,7,8};
    int target = 7;   // find 7 in the array and print its index
    ls(arr,target);
    return 0;
}