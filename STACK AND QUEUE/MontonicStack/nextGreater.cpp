#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreater(vector<int>& arr){
    int n = arr.size();
    stack<int>st;
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--){

        // removing 
        while(st.size() > 0 && st.top() < arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}
int main(){
    vector<int> arr = {6,8,0,1,3};
    vector<int> ans = nextGreater(arr);
    for(int val : ans){
        cout << val << " ";
    }
    return 0;
}