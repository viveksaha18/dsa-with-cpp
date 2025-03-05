#include<bits/stdc++.h>
using namespace std;
// Performing Quick sort 


// find the pivot and the partition 
int partition(vector<int> &arr , int low ,int high )
{
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high)
        {
            i++;
        }
        while(arr[j]>pivot && j>=low)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);   // gives pivot to correct position
    //return j;  // return the partition 
    for(auto it : arr){
        cout<<it;
    }
}
/*
void  qs(vector<int> &arr , int low , int high )
{
    if(low<high)
    {
        int pindex=partition(arr,low,high);
        qs(arr,low,pindex-1);// Recursively sort left portion
        qs(arr,pindex+1,high); //Recursively sort right portion
    }
}
*/
int main(){
    int n;
    cout<<"Enter the size of the array :"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];  //Input in the array 
    int low=0;
    int high=n-1;
    //qs(arr,low,high);
    // Array after quick sort 
   /* for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }*/
    partition(arr,low,high);
    
    return 0;
}