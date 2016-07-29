class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort()
        ans = []
        dp = [None for i in range(len(nums))]
        for i in range(len(dp)):
            dp[i] = [nums[i]]
            for j in range(i-1,-1,-1):
                if nums[i]%nums[j]==0 and len(dp[j])+1 > len(dp[i]):
                    dp[i] = dp[j] + [nums[i]]
            if len(dp[i]) > len(ans):
                ans = dp[i]
                
        return ans
                    
                    
        
