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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        if(k == 0) return head;
        vector<int> ans;
        ListNode* temp = head;
        while(temp != nullptr) {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        int n = ans.size();
        temp = head;
        k = k % n;
        rotate(ans.begin(), ans.end()-k, ans.end());
        int i = 0;
        while(temp != nullptr && i < n) {
            temp->val = ans[i];
            temp = temp->next;
            i++;
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
    int k = 2;
    ListNode* result = sol.rotateRight(head, k);
    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}