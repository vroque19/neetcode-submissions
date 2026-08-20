# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        # split list into 2 halves
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # second half starts at slow
        second = slow.next
        # reverse the 2nd half of list
        prev = None
        slow.next = prev
        while second:
            temp = second.next
            second.next = prev
            prev = second
            second = temp
        # reorder the list by traversing 1st list and 2nd list alternating between
        first = head
        second = prev
        while second:
            tmp1 = first.next
            tmp2 = second.next
            first.next = second
            second.next = tmp1
            first = tmp1
            second = tmp2
        