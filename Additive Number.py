class Solution(object):
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        if len(num)<3:
            return False
        for x in xrange(1,len(num)/2+1,1):
            for y in xrange(1,len(num)-2*x+1,1):
                if (not ((num[0]=='0'and x>1) or  (num[x]=='0' and y>1))) and self.goAdd(num,x,y):
                    print x,y
                    return True
        return False
        
    def goAdd(self,num,x,y):
        a = int(num[:x])
        b = int(num[x:x+y])
        c = str(a+b)
        if c in num[x+y:]:
            if len(c) == len(num[x+y:]):
                return True
            else:
                return self.goAdd(num[x:],y,len(c))
        else:
            return False
