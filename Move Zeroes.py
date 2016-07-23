class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i=0
        j=0
        
        while i<len(nums) and j<len(nums):
            while i<len(nums) and nums[i]!=0:
                i+=1
            while j<=i and j<len(nums):
                j+=1
            while j<len(nums) and nums[j]==0:
                j+=1
            if i<len(nums) and j<len(nums):
                tmp = nums[j]
                nums[j] = nums[i]
                nums[i] = tmp
        return
        
        
