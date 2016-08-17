class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==2:
            if nums[0]<nums[1]:
                return 1
            else:
                return 0
        left = 0
        right = len(nums)-1
        while True:
            mid = left + (right - left)/2
            if mid==0 or mid==len(nums)-1:
                return mid
            elif nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]:
                return mid
            elif nums[mid]<nums[mid+1]:
                left = mid+1
            elif nums[mid]<nums[mid-1]:
                right = mid
        
