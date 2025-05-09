#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {10,1,5};
    int maxi = 0;
    for(int i = 0;i < arr.size(); i++){
        int buy = arr[i];
        for(int j = i + 1; j < arr.size(); j++){
            int profit = arr[j] - buy;
            if(profit > buy){
                maxi = max(maxi,profit);
            }
        }
    }
    cout << maxi;

    return 0;
}
But give the timecomplexity of O(n*n) where n is the size of the array given 
