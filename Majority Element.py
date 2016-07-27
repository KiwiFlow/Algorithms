class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        count = 0
        for each in nums:
            if count == 0:
                ans = each
                count = 1
            else:
                if each == ans:
                    count+=1
                else:
                    count-=1
        return ans
                
            
                
        
