#include<bits/stdc++.h>
using namespace std;

/*Question --> You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.*/

/* Brute Force Appraoch
Go to every queries and change the array as per the requirement 

Time Complexity - O(n*(m+n))
Space Complexity - O(1)
*/
bool isZero(vector<int>& arr){
    for(int it : arr){
        if(it != 0) return false;
    }
    return true;
}

bool ZeroBrute(vector<int>& arr , vector<vector<int>>& q){
    int n = arr.size();
    int m = q.size();
    for(auto it : q){
        int st = it[0]; 
        int end = it[1];
        for(int i = st; i <= end; i++){
            arr[i] = max(0,arr[i] - 1);
        }
        if(isZero(arr)) return true;
    }
    return false;
}

/*
Optimal Solution ---> Here we have reduced the time complexity from O(n*(n+m)) to be like O(n+m) .
What can we do we can use a diff array concept here

Time Complexity - O(n+m) 
Space Complexity - O(n)
*/

bool ZeroOptimal(vector<int>& arr , vector<vector<int>> q){
    int n = arr.size();
    int m = q.size();

    vector<int> diff(n + 1 , 0);
    for(int i = 0; i < m; i++){
        int st = q[i][0];
        int end = q[i][1];
        diff[st]+=-1;
        diff[end + 1]+=1;
    }
    int cummulativeSum = 0;
    for(int i = 0; i < n; i++){
        cummulativeSum+=diff[i];
        if(cummulativeSum + arr[i] > 0) 
        return false;
    }
    return true;
}


/*
Binary Search Approach 

*/
bool isTrue( int k , vector<int>& arr ,vector<vector<int>>& q){
    int n = arr.size();
    vector<int> diff(n + 1 , 0);
    for(int i = 0; i < k; i++){
        int st = q[i][0];
        int end = q[i][1];
        diff[st]+=-1;
        diff[end + 1]+=1;
    }
    int cummulativeSum = 0;
    for(int i = 0; i < n; i++){
        cummulativeSum+=diff[i];
        if(cummulativeSum + arr[i] > 0) 
        return false;
    }
    return true;
}
bool ZeroOpimal1(vector<int>& arr ,vector<vector<int>>  q){
    int low = 0 , high = q.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(isTrue(mid , arr , q)) return true;
        else low = mid + 1;
    }
    return false;
}
int main(){
    vector<int> arr = {4,3,2,1};
    vector<vector<int>> q = {{1,3} , {1,2}};
    cout << ZeroBrute(arr , q);
    cout << endl;
    cout << ZeroOptimal(arr , q);
    cout << endl;
    cout << ZeroOpimal1(arr , q);
    return 0;
}