class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        ans=[]
        i=0
        while i<len(nums):
            j=i+1
            while j<len(nums) and nums[j]==nums[j-1]+1:
                j+=1
            if i!=j-1:
                ans.append(str(nums[i])+'->'+str(nums[j-1]))
            else:
                ans.append(str(nums[i]))
            i=j
        return ans
            
                
