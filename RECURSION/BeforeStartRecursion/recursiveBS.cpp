#include<bits/stdc++.h>
using namespace std;

int bsRecursive(vector<int> arr  , int st , int end , int tar){
    if(st <= end){
        int mid = (st + end) / 2;
        if(arr[mid] == tar) return mid;

        if(arr[mid] <= tar){
            // go to the second half 
            return bsRecursive(arr,mid+1,end,tar);
        }
        else{
            return bsRecursive(arr,st,mid-1,tar);
        }
    }
}
int main(){

    // we dont use loop to solve bs we use recursive approach 

    vector<int> arr = {1,2,4,5,6};
    int tar = 4;
    int st = 0 , end = arr.size() - 1;
    cout << bsRecursive(arr , st , end , tar) << endl;
    return 0;
}