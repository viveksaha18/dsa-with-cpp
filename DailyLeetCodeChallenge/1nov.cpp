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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(head != nullptr) {
            if(st.find(head->val) == st.end()) {
                tail->next = new ListNode(head->val);
                tail = tail->next;
            }
            head = head->next;
        }
        return dummy.next;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 4, 6};
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* result = sol.modifiedList(nums, head);
    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}