#include<bits/stdc++.h>
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
    void reorderList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> ans;
        int l = 0, r = arr.size()-1;
        while(l <= r) {
            if(l == r) {
                ans.push_back(arr[l]);
                break;
            }
            ans.push_back(arr[l]);
            ans.push_back(arr[r]);
            l++, r--;
        }
        temp = head;
        for(auto it : ans) {
            temp->val = it;
            temp = temp->next;
        }
    }
};
int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    s.reorderList(head);
    ListNode* temp = head;
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}