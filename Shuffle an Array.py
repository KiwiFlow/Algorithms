class Solution(object):

    def __init__(self, nums):
        """
        
        :type nums: List[int]
        :type size: int
        """
        self.nums = nums
        
        
        

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.nums
        

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        d = {}
        ret = []
        for i in self.nums:
            d[i] = None
        import random
        lens = len(self.nums)
        for i in range(len(self.nums)):
            j = (d.keys())[random.randint(0,lens-1)]
            ret.append(j)
            d.pop(j)
            lens-=1
        return ret
            
            
        
            
        
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
