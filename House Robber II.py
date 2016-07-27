class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums)<=3:
            return max(nums)
        return max(nums[0]+self.rob_(nums[2:len(nums)-1]),self.rob_(nums[1:len(nums)]))
    def rob_(self,nums):
        ans,ans_plus_1,ans_plus_2 = 0,0,0
        i=len(nums)-1
        while i>=0:
            ans = max(ans_plus_1,nums[i]+ans_plus_2)
            i-=1
            ans_plus_1,ans_plus_2 = ans,ans_plus_1
        return ans
