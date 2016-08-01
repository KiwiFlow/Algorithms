class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums)<2:
            return 1
            
        flag = nums[1]-nums[0]
        ans = 2
        
        for i in range(2,len(nums)):
            if (nums[i]-nums[i-1]>0 and flag<0) or \
            (nums[i]-nums[i-1]<0 and flag>0):
                ans+=1
                flag = -flag
                
        return ans
            
#证明贪心算法的正确性
