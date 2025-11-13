#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/remove-linked-list-elements/description/?envType=problem-list-v2&envId=recursion"


 
 struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int value) {
        // marking
        ListNode* temp = head;
        while(temp != nullptr) {
            if(temp->val == value) {
                temp->val = -1;
            }
            temp = temp->next;
        }

        temp = head;
        ListNode newNode(0);
        ListNode* node = &newNode;
        while(temp != nullptr) {
            if(temp->val != -1) {
                node->next = new ListNode(temp->val);
                node = node->next;
            }
            temp = temp->next;
        }

        return newNode.next;
        
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    int value = 6;
    ListNode* result = sol.removeElements(head, value);
    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}