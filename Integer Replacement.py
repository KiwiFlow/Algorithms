class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.d = {}
        return self.IR(n)
    def IR(self,n):
        if n in self.d:
            return self.d[n]
        else:
            if n==1:
                self.d[n]=0
            elif n%2==0:
                self.d[n]=self.IR(n/2)+1
            else:
                self.d[n]=min(self.IR((n+1)/2),self.IR((n-1)/2))+2
            return self.d[n]
