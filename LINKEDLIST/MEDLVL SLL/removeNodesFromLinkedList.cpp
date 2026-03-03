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
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while (temp != nullptr) {
            while (!st.empty() && st.top() < temp->val) {
                st.pop();
            }
            st.push(temp->val);
            temp = temp->next;
        }
        ListNode* newHead = nullptr;

        while (!st.empty()) {
            ListNode* node = new ListNode(st.top());
            node->next = newHead;
            newHead = node;
            st.pop();
        }

        return newHead;
    }
};
int main() {
    Solution s;
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);
    ListNode* newHead = s.removeNodes(head);
    while (newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    return 0;
}