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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        vector<int> ans;
        while(temp != nullptr) {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n = ans.size();
        swap(ans[k-1], ans[n-k]);
        temp=head;
        for(int i = 0; i < n; i++) {
            temp->val = ans[i];
            temp=temp->next;
        }
        return head;
    }
};


int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);
    head = s.swapNodes(head, 2);
    ListNode* temp = head;
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp=temp->next;
    }
    return 0;
}
