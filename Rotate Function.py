class Solution(object):
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        s = sum(A)
        pre = 0
        for i in xrange(len(A)):
        	pre = pre+A[i]*i
        res = pre
        for i in xrange(len(A)-1,0,-1):
        	cur = pre+s-len(A)*A[i]
        	res = max(res,cur)
        	pre = cur
        return res
