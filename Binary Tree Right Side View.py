# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root==None:
            return []
        ret=[root.val]
        left = self.rightSideView(root.left)
        right = self.rightSideView(root.right)
        for each in right:
            ret.append(each)
        i = len(right)
        while i<len(left):
            ret.append(left[i])
            i+=1
        return ret
            
        
