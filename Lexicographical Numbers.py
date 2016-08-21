class Solution(object):
    def next_(self,i,n):
        if i*10 <= n:
            return i*10
        else:
            if i%10<9 and i+1<=n:
                return i+1
            elif i%10<9 and i+1>n:
                i = i/10
                while i%10==9:
                    i = i/10
                return i+1
            elif i%10==9:
                while i%10==9:
                    i = i/10
                return i+1
                    
            
        
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        if n<1:
            return []
        result = [0 for i in xrange(n)]
        result[0] = 1
        for i in xrange(1,n,1):
            result[i]=self.next_(result[i-1],n)
            #print result[i]
        return result
                    
                
