#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> p1, pair<int,int> p2) {
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    if(p1.first > p2.first) return true;
    return false;
}
int main() {
    pair<int,int> a[] = {{1,2}, {2,1}, {4,1}};
    int n = sizeof(a)/sizeof(a[0]);
    // sort it according to second element
    // if second element is same then sort in descending order according to the first element

    sort(a, a+n, comp);
    for(auto it : a) {
        cout << it.first << it.second;
        cout << endl;
    }
    return 0;
}