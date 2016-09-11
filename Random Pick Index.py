class Solution(object):

    def __init__(self, nums):
        """
        
        :type nums: List[int]
        :type numsSize: int
        """
        self.nums = nums
        self.d = {}
        for i in xrange(len(nums)):
            if nums[i] in self.d:
                self.d[nums[i]]+=1
            else:
                self.d[nums[i]] = 1
        

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        import random
        x = random.randint(1,self.d[target])
        for i in xrange(len(self.nums)):
            if self.nums[i] == target:
                if x == 1:
                    return i
                else:
                    x-=1
       
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
