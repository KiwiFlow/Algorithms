# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):

    def __init__(self, head):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self.length = 0
        self.head = head
        while head:
            self.length+=1
            head=head.next
        

    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        import random
        r = random.randint(0,self.length-1)
        ret = self.head
        for i in range(r):
            ret = ret.next
        return ret.val
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
