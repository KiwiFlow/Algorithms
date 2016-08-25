class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = 0
        i = 1
        while i<=n:
            res += (n/i+8)/10*i
            if (n/i)%10==1:
                res+=(n%i+1)
            i*=10
        return res
        
        
