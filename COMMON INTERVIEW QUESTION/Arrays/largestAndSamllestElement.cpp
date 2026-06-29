#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter the size of the array";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    // Largest Element
    cout << arr[n-1];
    // Smallest Element
    return 0;
}