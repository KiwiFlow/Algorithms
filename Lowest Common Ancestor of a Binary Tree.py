# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def lowestCommonAncestor(self, root, p, q):
        record={root:None} #node->parent
        self.getParent(root,record)
        
        pList = [p]
        qList = [q]
        
        cur=p
        while record[cur]!=None:
            pList.append(record[cur])
            cur=record[cur]
       
        cur=q
        while record[cur]!=None:
            qList.append(record[cur])
            cur=record[cur]
        
        i = -min(len(pList),len(qList))
        j = -1
        
        while j>=i:
            if pList[j].val!=qList[j].val:
                break
            j-=1
        return pList[j+1]
                
        
        
    def getParent(self,root,record):
        if root == None:
            return
        if root.left==None and root.right==None:
            return
        if root.left!=None:
            record[root.left]=root
            self.getParent(root.left,record)
        if root.right!=None:
            record[root.right]=root
            self.getParent(root.right,record)
        
        
    
    
    
