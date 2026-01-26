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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        temp = temp->next;
        int sum = 0;
        while(temp != nullptr) {
            if(temp->val == 0) {
                arr.push_back(sum);
                sum = 0;
            }
            else sum+=temp->val;
            temp = temp->next;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        for(int x : arr) {
            current->next = new ListNode(x);
            current = current->next;
        }
        return dummy->next;
    }
};
int main() {
    Solution s;
    ListNode* head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(0);
    ListNode* result = s.mergeNodes(head);
    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}