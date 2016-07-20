class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        i=0
        j=0
        subsum=0
        min_val=len(nums)+1
        while j<len(nums):
            while j<len(nums) and subsum<s:
                subsum+=nums[j]
                j+=1
            while subsum>=s:
                min_val=min(min_val,j-i)
                subsum-=nums[i]
                i+=1
        if min_val==len(nums)+1:
            return 0
        else:
            return min_val
"""
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
"""
