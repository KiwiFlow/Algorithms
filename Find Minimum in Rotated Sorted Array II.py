class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)<3:
            return min(nums)
        left,right = 0,len(nums)-1
        while left < right-1:
            mid = left +(right-left)/2
            if nums[left]<nums[right]:
                return nums[left]
            elif nums[mid] > nums[left]:
                left = mid
            elif nums[mid] < nums[left]:
                right = mid
            else:
                left+=1
        return min(nums[left],nums[right])
                
