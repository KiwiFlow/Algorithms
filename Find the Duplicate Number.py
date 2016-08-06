class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 1
        right = len(nums)-1
        while left <= right:
            if left == right:
                return left
            mid = left + (right-left)/2
            left_part = 0
            right_part = 0
            
            for each in nums:
                if each>=left and each <= mid:
                    left_part+=1
                elif each>mid and each<=right:
                    right_part+=1
            if left_part > mid-left+1:
                right = mid
            elif right_part > right-mid:
                left = mid+1
        return 0
                
                
                
        
