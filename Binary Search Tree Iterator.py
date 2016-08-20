# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.s = []
        self.root = root

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.s or self.root
        

    def next(self):
        """
        :rtype: int
        """
        k=0
        while self.hasNext():
            if self.root:
                self.s.append(self.root)
                self.root=self.root.left
            else:
                self.root = (self.s)[-1]
                k=self.root.val
                self.s.pop()
                self.root = self.root.right
                break
        return k

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
