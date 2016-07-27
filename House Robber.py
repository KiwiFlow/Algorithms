class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        ans = [0 for i in range(len(nums)+2)]
        i=len(nums)-1
        while i>=0:
            ans[i] = max(ans[i+1],nums[i]+ans[i+2])
            i-=1
        return ans[0]
            
        
