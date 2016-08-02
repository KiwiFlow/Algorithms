class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        ic = {}
        for i in nums:
            if i in ic.keys():
                ic[i]+=1
            else:
                ic[i]=1
        h = []
        for key,value in ic.iteritems():
            heapq.heappush(h,(value,key))
        return map(lambda x:x[1],heapq.nlargest(k,h))
            
        
        
