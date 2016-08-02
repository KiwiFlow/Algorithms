class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==0:
            return 1
        if n==1:
            return 10
        if n==2:
            return 91
        base = [0 for i in range(n+1)]
        base[0]=0
        base[1]=10
        base[2]=81
        ans = base[0]+base[1]+base[2]
        for i in range(3,n+1,1):
            base[i] = (11-i)*base[i-1]
            ans += max(0,base[i])
        return ans
            
        
