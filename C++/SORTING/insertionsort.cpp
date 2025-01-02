#include<bits/stdc++.h>
using namespace std;

// Performing Insertion Sort 
int* insertionsort(int arr[], int n){
    int j;
    for(int i=0;i<=n-1;i++){
        j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
    return arr;
}
int main(){
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<n;i++)  cin>>arr[i];
    insertionsort(arr,n);
    cout<<endl;
    cout<<"Array after performing insertion sort : "<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}