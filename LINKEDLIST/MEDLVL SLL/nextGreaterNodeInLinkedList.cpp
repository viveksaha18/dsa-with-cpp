#include <bits/stdc++.h>
using namespace std;


  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        ListNode* temp =  head;
        while(temp != nullptr) {
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n = v.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && v[i] > v[st.top()]) {
                ans[st.top()] = v[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);
    vector<int> ans = s.nextLargerNodes(head);
    for(int i : ans) {
        cout << i << " ";
    }
    return 0;
}   