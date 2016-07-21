# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        cur = root
        while cur:
            if cur.val == p.val or cur.val==q.val:
                break
            elif cur.val>p.val and cur.val>q.val:
                cur=cur.left
            elif cur.val<p.val and cur.val<q.val:
                cur=cur.right
            else:
                break
        return cur
