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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr) return nullptr;
        vector<int> ans;
        ListNode* temp = head;
        while(temp != nullptr) {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        reverse(ans.begin()+left-1, ans.begin()+right);
        for(int i = 0; i < ans.size(); i++) {
            temp->val = ans[i];
            temp = temp->next;
        }
        return head;
    }
};
int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int left = 2, right = 4;
    ListNode* result = sol.reverseBetween(head, left, right);
    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}