class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        self.used = [0 for x in xrange(10)]
        return self.go(k,n)
            
    def go(self,k,n):
        res = []
        if k==0 or n==0:
            return res
        if k==1 and n<=9 and n>=1 and self.used[n]==0:
            return [[n]]
        for i in xrange(1,10,1):
            if self.used[i]==0:
                self.used[i] = 1
                ret = self.go(k-1,n-i)
                for each in ret:
                    each.append(i)
                    each.sort()
                    if each not in res:
                        res.append(each)
                self.used[i] = 0
        return res
                
            
            
            
            
        
        
