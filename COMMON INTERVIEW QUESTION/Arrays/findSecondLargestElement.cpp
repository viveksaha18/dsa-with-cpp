#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {2, 3, 4, 23, 1, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int l = arr[0];
    int slargest = -1;
    for(int i = 1; i < n; i++) {
        if(arr[i] > l) {
            slargest=l;
            l=arr[i];
        }
        else if(arr[i] < l && slargest < arr[i]) slargest=arr[i];
    }
    cout << slargest;
    return 0;
}