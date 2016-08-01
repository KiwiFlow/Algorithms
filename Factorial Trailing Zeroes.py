class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        base = 5
        while n/base>0:
            ans += n/base
            base = base*5
        return ans
