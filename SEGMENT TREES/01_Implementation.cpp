#include<bits/stdc++.h>
using namespace std;
class SegmentTree {
    public:
    vector<int> segTree;
    SegmentTree(int n) {
        segTree.resize(4*n);
    }
    void buildSegTree(int i, int l, int r, vector<int>& arr) {
        if(l == r) {
            segTree[i]=arr[l];
            return;
        }
        int mid = l+(r-l)/2;
        buildSegTree(2*i+1, l, mid, arr);
        buildSegTree(2*i+2, mid+1, r, arr);
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
};
int main() {
    vector<int> arr={1, 2, 3, 4, 5, 6, 7, 8};
    int n = arr.size();
    SegmentTree st(n);
    int l = 0, r = n-1;
    st.buildSegTree(0, l, r, arr);
    for(int i = 0; i < st.segTree.size(); i++) cout << st.segTree[i] << " ";
    return 0;
}