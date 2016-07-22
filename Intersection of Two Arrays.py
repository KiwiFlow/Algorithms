class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        shorter = None
        longer = None
        if len(nums1) < len(nums2):
            shorter = nums1
            longer = nums2
        else:
            shorter = nums2
            longer = nums1
        k = set(shorter)
        ret=[]
        for each in longer:
            if (each in k) and (each not in ret):
                ret.append(each)
        return ret
