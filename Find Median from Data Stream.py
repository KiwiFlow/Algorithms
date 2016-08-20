class MedianFinder:
    import heapq
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.leftHeap = []
        self.rightHeap = []
        

    def addNum(self, num):
        """
        Adds a num into the data structure.
        :type num: int
        :rtype: void
        """
        if not self.leftHeap:
            heapq.heappush(self.leftHeap,num*-1)
            return
        elif not self.rightHeap:
            if heapq.nsmallest(1,self.leftHeap)[0]*-1 > num:
                heapq.heappush(self.rightHeap,heapq.heappop(self.leftHeap)*-1)
                heapq.heappush(self.leftHeap,num*-1)
            else:
                heapq.heappush(self.rightHeap,num)
            return
        
        if num<= heapq.nsmallest(1,self.leftHeap)[0]*-1:
            heapq.heappush(self.leftHeap,num*-1)
        else:
            heapq.heappush(self.rightHeap,num)
        
        while len(self.leftHeap)-len(self.rightHeap)>1:
            heapq.heappush(self.rightHeap,heapq.heappop(self.leftHeap)*-1)
            
        while len(self.rightHeap)-len(self.leftHeap)>1:
            heapq.heappush(self.leftHeap,heapq.heappop(self.rightHeap)*-1)
            
            
            
            
        
        

    def findMedian(self):
        """
        Returns the median of current data stream
        :rtype: float
        """
        if len(self.leftHeap) == len(self.rightHeap):
            return float(heapq.nsmallest(1,self.leftHeap)[0]*-1+heapq.nsmallest(1,self.rightHeap)[0])/2
        elif len(self.leftHeap) > len(self.rightHeap):
            return float(heapq.nsmallest(1,self.leftHeap)[0]*-1)
        else:
            return float(heapq.nsmallest(1,self.rightHeap)[0])
       
        

# Your MedianFinder object will be instantiated and called as such:
# mf = MedianFinder()
# mf.addNum(1)
# mf.findMedian()
