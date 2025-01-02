#include<bits/stdc++.h>
using namespace std;

// performing selection sort 
int* selectionsort( int n, int arr[]){
    int min;
    for(int i=0;i<=n-2;i++){
        // assume i as the minimum 
        min=i;
        // inner loop 
        for(int j=i;j<=n-1;j++){         // it can also start from j=i+1
            if(arr[j]<arr[min])
            min=j;   // update minimum if our assumption is wrong 
        }
        swap(arr[min],arr[i]);
    }
    return arr;
}
int main(){
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    selectionsort(n,arr);
    cout<<endl;
    cout<<"Enter the sorted array : "<<endl;
    // Sorted array 
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    
    return 0;
}