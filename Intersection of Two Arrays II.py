class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        ans = []
        bigger = None
        smaller = None
        if len(nums1) < len(nums2):
            bigger,smaller = nums2,nums1
        else:
            bigger,smaller = nums1,nums2
        record = {}
        for each in smaller:
            if each not in record.keys():
                record[each]=1
            else:
                record[each]+=1
        
        for each in bigger:
            if each in record.keys() and record[each]>=1:
                ans.append(each)
                record[each]-=1
        return ans
            
            
        
        
