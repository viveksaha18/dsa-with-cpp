#include<bits/stdc++.h>
using namespace std;
/*
In an array of integers n, the prefix sum array is the array whose every element is the sum of all elements, 
of the original array, up to the current index.
Given an array of n=5 , array[]={1,2,3,4,5}
Its Prefix Sum array will be p[].
p[0]=array[0]=1;
p[1]=array[0]+array[1]=1+2=3;
p[2]=array[0]+array[1]+array[2]=1+2+3=6;
p[3]=array[0]+array[1]+array[2]+array[3]=1+2+3+4=10;
p[4]=array[0]+array[1]+array[2]+array[3]+array[4]=1+2+3+4+5=15;
Final Prefix Sum Array would be={1,3,6,10,15}

*/
int main(){
    int arr[] = {1,2,3,4,5};
    int prefixSum[5];
    prefixSum[0] = arr[0];

    for(int i = 1; i < 5; i++){
        prefixSum[i] = prefixSum[i-1]+arr[i];
    }
    for(auto it : prefixSum){
        cout<<it<<" ";
    }
    return 0;
}