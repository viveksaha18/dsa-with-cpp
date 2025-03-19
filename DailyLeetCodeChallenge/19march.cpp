#include<bits/stdc++.h>
using namespace std;

/*
Question and Explanation 
You are given a binary array nums.

You can do the following operation on the array any number of times (possibly zero):

Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.

 

Example 1:

Input: nums = [0,1,1,1,0,0]

Output: 3

Explanation:
We can do the following operations:

Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].
Example 2:

Input: nums = [0,1,1,1]

Output: -1

Explanation:
It is impossible to make all elements equal to 1.
*/


/*
Time Complexity : O(n)
Space Complexity : O(1)
*/
int minimumOperation(vector<int>& arr){
    int minOpratn = 0;
    int n = arr.size();
    for(int i = 0; i < (n - 2); i++){
        if(arr[i] != 0) continue;
        for(int j = i; j <= (2 + i); j++){
            if(arr[j] == 0){
                arr[j] = 1;
            }
            else{
                arr[j] = 0;
            }
        }
        minOpratn++;
    }
    for(int it : arr){
        if(it != 1){
            return -1;
        }
    }
    return minOpratn;
}

/*
Using xor operator 
Time Complexity : O(n)
Space Complexity : O(1)
*/

int minimumOpratn(vector<int>& arr){
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < (n - 2); i++){
        if(arr[i] == 0){
            arr[i]^=1;
            arr[i + 1]^=1;
            arr[i + 2]^=1;
            cnt++;
        }
    }
    for(int it : arr){
        if(it == 0) return -1;
    }
    return cnt;
}
int main(){
    vector<int> arr = {0,1,1,1,0,0};
    //int ans = minimumOperation(arr);
   // cout << ans << endl;

    // By using xor opearator 
    int soln = minimumOpratn(arr);
    cout << soln << endl;
    return 0;
}