class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        s = sorted(nums)
        right = len(nums)-1
       
        if len(nums)%2==0:
             left = len(nums)/2-1
        else:
            left = len(nums)/2
        for i in xrange(len(nums)):
            if i%2==0:
                nums[i]=s[left]
                left-=1
            else:
                nums[i]=s[right]
                right-=1
        
