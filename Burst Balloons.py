class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [1] + nums + [1]
        M = len(nums)
        r = [[0 for i in range(M)] for j in range(M)]
        
        for step in range(1,M-1):
            for i in range(1,M-step):
                for k in range(i,i+step):
                    r[i][i+step-1]=max(r[i][i+step-1],r[i][k-1]+nums[k]*\
                    nums[i-1]*nums[i+step]+r[k+1][i+step-1])
        return r[1][M-2]
                
                    
                
            
        
        
