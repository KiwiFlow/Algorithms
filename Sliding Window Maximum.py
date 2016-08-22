class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if k<1:
            return []
        from heapq import *
        h = [i*-1 for i in nums[0:k]]
        heapify(h)
        result = []
        deleted = {}
        for i in range(0,len(nums)-k+1):
            if i==0:
                result.append(h[0]*-1)
            else:
                if nums[i-1]*-1 in deleted:
                    deleted[nums[i-1]*-1] +=1
                else:
                    deleted[nums[i-1]*-1] = 1
                    
                heappush(h,nums[i+k-1]*-1)
                while h and (h[0] in deleted) and deleted[h[0]]>0:
                    deleted[h[0]]-=1
                    heappop(h)
                result.append(h[0]*-1)
        return result
                
            
            
        
