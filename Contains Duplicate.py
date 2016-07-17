class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        my_set = set()
        for each in nums:
            if each in my_set:
                return True
            my_set |= set([each])
        return False
