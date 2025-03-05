#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maximumRectangleScore(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    unordered_map<int, int> mpp;

    // Count occurrences of 2×2 identical submatrices
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (arr[i][j] == arr[i][j+1] && arr[i][j] == arr[i+1][j] && arr[i][j] == arr[i+1][j+1]) {
                mpp[arr[i][j]]++;
                cout << "Found 2x2 Square of " << arr[i][j] << " at (" << i << "," << j << ")" << endl;
            }
        }
    }

    // Debugging: Print frequency map
    cout << "\nFrequency Map:" << endl;
    for (auto it : mpp) {
        cout << it.first << " -> " << it.second << endl;
    }

    // Find the most frequent element (largest in case of a tie)
    int maxCount = 0;
    int maxEle = 0;
    for (auto it : mpp) {
        if (it.second > maxCount || (it.second == maxCount && it.first > maxEle)) {
            maxCount = it.second;
            maxEle = it.first;
        }
    }

    return maxEle;
}

// Example Usage
int main() {
    vector<vector<int>> arr = {
        {96, 77, 10, 69, 23, 62, 48, 12, 22, 24},
        {97, 70, 62, 75, 97, 18, 15, 48, 14, 75},
        {97, 55,  1, 74, 60, 67, 15, 95, 20, 18},
        {47, 40, 35, 26, 27, 80, 51, 52, 81, 57},
        {37, 69, 69, 69, 69, 65, 65, 65, 65, 65},
        {23, 69, 69, 69, 69, 65, 65, 65, 65, 65},
        {88, 69, 69, 69, 69, 65, 65, 65, 65, 65},
        {9,   6, 96, 78, 77, 65, 65, 65, 65, 65},
        {88, 58, 13, 26, 20, 65, 65, 65, 65, 65}
    };

    cout << "\nMaximum Rectangle Score: " << maximumRectangleScore(arr) << endl;
    return 0;
}
