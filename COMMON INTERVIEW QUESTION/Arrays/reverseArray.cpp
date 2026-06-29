#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {1, 2, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, arr+n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    int i = 0, j = n-1;
    while(i < j) {
        swap(arr[i], arr[j]);
        i+=1;
        j-=1;
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}