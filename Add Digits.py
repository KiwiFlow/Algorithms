class Solution(object):
    def addDigits(self,num):
        if num==0:
            return 0
        else:
            return 1+(num-1)%9
"""
    def addDigits(self, num):
        j = num
        i = self.addDig(num)
        while i!=j:
            j=i
            i=self.addDig(i)
        return i
      
            
    def addDig(self,num):
        ans = 0
        while num > 0:
            ans = ans + num%10
            num = num/10
        return ans
"""
    
            
