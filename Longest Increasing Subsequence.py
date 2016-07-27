class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        ans = 1
        dp = [0 for i in range(len(nums))]
        for i in xrange(len(nums)-1,-1,-1):
            if i==len(nums)-1:
                dp[i]=1
            else:
                j = i+1
                dp[i] = 1
                while j<len(nums):
                    if dp[i]==len(nums)-i:
                        break
                    if nums[i]>=nums[j] and nums[j]==1:
                        break
                    if nums[i]<nums[j]:
                        dp[i]=max(dp[i],dp[j]+1)
                    elif nums[i] == nums[j]:
                        dp[i]=max(dp[i],dp[j])
                    j+=1
            ans = max(ans,dp[i])
        return ans
                
        
