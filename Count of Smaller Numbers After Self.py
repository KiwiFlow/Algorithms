"""
TLE
class Node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None
        self.less = 0 #记录子树中 < Node.val的节点的个数
        self.equal = 1 #记录子树中 = Node.val的节点的个数
    def flush(self):
        self.less += 1
        if self.left:
            self.left.flush()
        if self.right:
            self.right.flush()
        
class Solution(object):
    def countSmaller(self, nums):
        if not nums:
            return []
        r = []
        root = Node(nums[-1])
        r.append(0)
        
        for i in range(len(nums)-2,-1,-1):
            p = root
            k = 0
            while True:
                if p.val < nums[i]:
                    k = p.less + p.equal
                    if p.right:
                        p = p.right
                    else:
                        p.right = Node(nums[i])
                        p.right.less = k
                        break
                elif p.val == nums[i]:
                    k = p.less
                    p.equal += 1
                    if p.right:
                            p.right.flush()
                    break
                else:
                    p.less+=1
                    if p.right:
                            p.right.flush()
                    if p.left:
                        p = p.left
                    else:
                        p.left = Node(nums[i])
                        p.left.less = k
                        break
            r.append(k)
        r.reverse()
        return r
"""

class Node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None
        self.less = 0 #记录子树中 < Node.val的节点的个数
        self.equal = 1 #记录子树中 = Node.val的节点的个数
        
class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []
        r = []
        root = Node(nums[-1])
        r.append(0)
        for i in range(len(nums)-2,-1,-1):
            p = root
            k = 0
            while True:
                if p.val < nums[i]:
                    k = k + p.less + p.equal
                    if p.right:
                        p = p.right
                    else:
                        p.right = Node(nums[i])
                        break
                elif p.val == nums[i]:
                    k = k + p.less
                    p.equal += 1
                    break
                else:
                    p.less+=1
                    if p.left:
                        p = p.left
                    else:
                        p.left = Node(nums[i])
                        break
            r.append(k)
        r.reverse()
        return r
