#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *temp = head;
        vector<int> ans;
        while (temp != nullptr)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        sort(ans.begin(), ans.end());
        int i = 0;
        temp = head;
        while (temp != nullptr)
        {
            temp->val = ans[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};
int main()
{
    Solution s;
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    ListNode *sortedHead = s.insertionSortList(head);
    while (sortedHead != nullptr)
    {
        cout << sortedHead->val << " -> ";
        sortedHead = sortedHead->next;
    }
    return 0;
}