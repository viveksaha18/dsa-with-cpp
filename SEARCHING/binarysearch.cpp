#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& arr, int k) {

        // Your code here
          int mid;
        int result =-1;
        int n = arr.size();
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            mid = (left +right)/2;
            if(arr[mid]<=k) 
            {
                result = mid;
                left=mid+1;
            }
            else 
                right=mid -1;
        }
        cout<<result;
    }
int main(){
    vector<int> arr = {1, 2, 8, 10, 11, 12, 19};
    int k = 5;
    findFloor(arr,k);
    return 0;
}