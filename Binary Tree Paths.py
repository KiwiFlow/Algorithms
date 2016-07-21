# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        if not root:
            return []
        if root.left==None and root.right==None:
            return [str(root.val)]
        left = self.binaryTreePaths(root.left)
        right = self.binaryTreePaths(root.right)
        ret = []
        for each in left:
            ret.append(str(root.val)+'->'+each)
        for each in right:
            ret.append(str(root.val)+'->'+each)
        return ret
        
