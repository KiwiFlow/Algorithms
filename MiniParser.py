# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
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

class Solution(object):
	def token(self,s):
		t = []
		i = 0
		while i<len(s):
			if s[i]=='[' or s[i] ==']':
				t.append(s[i])
				i+=1
			elif s[i] == ',':
				i+=1
			else:
				n = 0
				while i<len(s) and ord(s[i])>=ord('0') and ord(s[i])<=ord('9'):
					n = n*10 + ord(s[i])-ord('0')
					i+=1
				t.append(n)
		return t
	def deserialize(self, s):
		t = self.token(s)
		s = []
		for each in t:
		    if each == '[':
		        k = NestedInteger()
		        s.append(k)
		    elif each == ']':
		        r = s.pop()
		        if s:
		            (s[-1].getList()).append(r)
		        else:
		            return r
		    else:
		        if s:
		            s[-1].add(each)
		        else:
		            return NestedInteger(each)
		            
		         
