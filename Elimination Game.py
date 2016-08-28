class Solution(object):
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        """
        x = [0 for x in xrange(n+1)]
        temp = [0,1,2,2,2,2,4,4,6,6]
        if n<10:
            return temp[n]
        for i in xrange(10):
            x[i] = temp[i]
            
        for i in xrange(10,n+1,1):
            if i%2==1:
                x[i]=x[i-1]
            else:
                if i%4==0:
                    x[i] = 4*(x[i-i/2-i/4]-1)+2
                else:
                    x[i] = 4*(x[i-i/2-i/4-1]-1)+4
        return x[i]
        """
        temp =  [0,1,2,2,2,2,4,4,6,6]
        if n<10:
            return temp[n]
        elif n%2==1:
            return self.lastRemaining(n-1)
        elif n%4==0:
            return 4*(self.lastRemaining(n/4)-1)+2
        else:
            return 4*(self.lastRemaining(n/2-n/4-1)-1)+4
