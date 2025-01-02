#include <bits/stdc++.h>
using namespace std;

// Function declarations
void msort(vector<int> &arr, int low, int high);
void mrg(vector<int> &arr, int low, int mid, int high);

// Merge sort based on the concept of multiple recursion 
void msort(vector<int> &arr, int low, int high) {
    if (low >= high) return; // Base case
    int mid = (low + high) / 2;
    msort(arr, low, mid);       // Sort left half
    msort(arr, mid + 1, high);  // Sort right half
    mrg(arr, low, mid, high);   // Merge sorted halves
}

// Here the merge happens 
void mrg(vector<int> &arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp; // Temporary array for merging 

    // Merge the two subarrays into temp
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Add remaining elements from the left subarray
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Add remaining elements from the right subarray
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the merged elements back to the original array
    for (int i = low; i <=high; i++) {
        arr[i]=temp[i-low];
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n); // Initialize the vector with size n
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    msort(arr, 0, n - 1); // Call the msort function to sort the array

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
