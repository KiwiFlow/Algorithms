class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.nums=[0] #index from one
        self.nums += nums
        self.bit = [0 for i in range(len(self.nums))]
        
        for i in range(len(self.bit)):
            sum=0
            for j in range(i,i-(i&(-i)),-1):
                sum+=self.nums[j]
            self.bit[i]=sum
            
        
        
    def prefixSum(self,i):
    	i+=1
        if i==0:
            return 0
        sum=0
        
        while i>0:
            sum+=self.bit[i]
            i-=(i&(-i))
        return sum
        

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: int
        """
        i+=1
        diff = val-self.nums[i]
        self.nums[i]=val
        while i<len(self.nums):
            self.bit[i]+=diff
            i+=(i&(-i))
            

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
      
        return self.prefixSum(j)-self.prefixSum(i-1)
