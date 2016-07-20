class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return (len(nums)*len(nums)+len(nums))/2 - sum(nums)
