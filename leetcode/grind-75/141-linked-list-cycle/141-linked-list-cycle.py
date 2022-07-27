# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return False
        
        seen = {}
        while head:
            if head in seen:
                if seen[head] == head.next:
                    return True
            seen[head] = head.next
            head = head.next
        return False