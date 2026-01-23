# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        if l1 is None and l2 is None :
            return None
        arr1 = []
        arr2 = []
        temp = l1
        while temp is not None :
            arr1.append(temp.val)
            temp = temp.next
        temp = l2
        while temp is not None:
            arr2.append(temp.val)
            temp = temp.next
        num1=0
        num2=0
        for x in arr1:
            num1=num1*10+x
        for x in arr2:
            num2=num2*10+x
        sum_val=num1+num2
        if sum_val == 0:
            return ListNode(0)
        ans=[]
        while sum_val > 0 :
            ans.append(sum_val%10)
            sum_val //= 10
        ans.reverse()
        dummy = ListNode(0)
        curr = dummy
        for x in ans:
            curr.next =  ListNode(x)
            curr = curr.next
        return dummy.next