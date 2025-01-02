#include<bits/stdc++.h>
using namespace std;
// Performing Bubble sort 
int*  bubblesort(int n, int arr[]){
    
    for (int  i=n-1; i>=1;i--)
    {
        for (int j=0;j<=i-1;j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return arr;
}
int main(){
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int*arr=new int[n];
    cout<<"Enter the elements in the array : "<<endl;
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    bubblesort(n,arr);
    cout<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}