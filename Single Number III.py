class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        a = 0
        for each in nums:
            a = a^each
        group = a&(-a)
        
        ans = [0,0]
        
        for each in nums:
            if each & group:
                ans[0] = ans[0]^each
            else:
                ans[1] = ans[1]^each
        return ans
        
        
