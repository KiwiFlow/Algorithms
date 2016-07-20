class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        record = [0 for i in range(n+1)]
        record[1]=1
        for i in range(2,n+1):
            max_val = -1
            for j in range(1,i/2+1):
                k=i-j
                max_val = max(max_val,max(j,record[j])*max(k,record[k]))
            record[i]=max_val
        return record[n]
                
"""
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.
"""
