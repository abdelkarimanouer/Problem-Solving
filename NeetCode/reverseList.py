# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        current = head
        l = []
        while current:
            l.append(current.val)
            current = current.next
        l.reverse()
        i = 0
        current = head
        while current:
            current.val = l[i]
            i += 1
            current = current.next

        return head
