//  arr = [1 2 3 4 5 6 7 ] k = 2 
#include<bits/stdc++.h>
using namespace std;

void reverseNK(vector<int>& arr, int end) {
    int l = 0; 
    while(l < end) {
        swap(arr[l], arr[end]);
        l++;
        end--;
    }
}
void reverseKN(vector<int>& arr, int st) {
    int end = arr.size()-1;
    while(st < end) {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    reverse(arr.begin(), arr.end());
    reverseNK(arr, arr.size()-k-1);
    reverseKN(arr, arr.size()-k);
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}