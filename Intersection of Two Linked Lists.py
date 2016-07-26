# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        AStack = []
        BStack = []
        while headA:
            AStack.append(headA)
            headA=headA.next
        while headB:
            BStack.append(headB)
            headB=headB.next
        ans = None
        while AStack and BStack:
            if AStack[-1] != BStack[-1]:
                break
            else:
                ans=AStack[-1]
                AStack.pop()
                BStack.pop()
        return ans
            
