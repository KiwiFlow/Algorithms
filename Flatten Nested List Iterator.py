# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        from collections import deque
        self.d = deque()
        self.queue(nestedList)
        #print self.d
        
    def queue(self,List):
        for each in List:
            if each.getInteger()!=None:
                self.d.append(each.getInteger())
            else:
                self.queue(each.getList())
            

            

    def next(self):
        """
        :rtype: int
        """
        #find next
        return self.d.popleft()
        
            
        

    def hasNext(self):
        """
        :rtype: bool
        """
        if self.d:
            return True
        else:
            return False
        

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
