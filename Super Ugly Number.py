class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        if n==1:
            return 1
        from heapq import *
        from collections import deque
        fronts = [(primes[i],i) for i in xrange(len(primes))]
        heapify(fronts)
        queues = [deque([primes[i]]) for i in xrange(len(primes))]
        count = 2
        res = 0
        while count<=n:
            res,k = heappop(fronts)
            queues[k].popleft()
            index = k
            while k < len(primes):
                queues[k].append(res*primes[k])
                k+=1
            heappush(fronts,(queues[index][0],index))
            count+=1
        return res
            
            
        
