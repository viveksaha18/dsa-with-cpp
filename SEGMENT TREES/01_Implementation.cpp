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
    void updateSegTree(int idx, int val, int i, int l, int r) {
        if(l == r) {
            segTree[i]=val;
            return;
        }
        int mid = l+(r-l)/2;
        if(idx <= mid)updateSegTree(idx, val, 2*i+1, l, mid);
        else updateSegTree(idx, val, 2*i+2, mid+1, r);
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    int rangeSum(int i, int l, int r, int start, int end) {
        if(r < start || end < l) return 0;
        if(l <= start && end <= r) return segTree[i];
        int mid = start+(end-start)/2;
        int leftSum = rangeSum(2*i+1, l, r, start, mid);
        int rightSum = rangeSum(2*i+2, l, r, mid+1, end);
        return leftSum + rightSum;
    }
};
int main() {
    vector<int> arr={1, 2, 3, 4, 5, 6, 7, 8};
    int n = arr.size();
    SegmentTree st(n);
    int l = 0, r = n-1;
    st.buildSegTree(0, l, r, arr);
    for(int i = 0; i < st.segTree.size(); i++) cout << st.segTree[i] << " ";
    int idx = 1;
    int val = 2;
    st.updateSegTree(idx, val, 0, l, r);
    int start = 2, end = 5;
    int queryRangeSum = st.rangeSum(0, l, r, 0, n-1);
    cout << queryRangeSum;
    return 0;
}