# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        result = ''
        from collections import deque
        d = deque()
        d.append(root)
        while d:
            p = d.popleft()
            if p:
                d.append(p.left)
                d.append(p.right)
                result = result + str(p.val) + '/'
            else:
                result = result + 'N' +'/'
        return result
            
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        print data
        from collections import deque
        d = deque(data.split('/'))
        d.pop()
        print d
        preLevel = deque()
        root = None
        if d[0] == 'N':
            return root
        else:
            root = TreeNode(int(d[0]))
            preLevel.append(root)
            d.popleft()
        flag = 0
        while d:
            p = d.popleft()
            if p == 'N':
                if flag%2==0:
                    preLevel[0].left = None
                else:
                    preLevel[0].right = None
                    preLevel.popleft()
                flag+=1
            else:
                k = TreeNode(int(p))
                preLevel.append(k)
                if flag%2==0:
                    preLevel[0].left = k
                else:
                    preLevel[0].right = k
                    preLevel.popleft()
                flag+=1
        return root
                
        
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
"""
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
"""
