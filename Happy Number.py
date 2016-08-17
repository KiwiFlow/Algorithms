def happy(n):
    s = str(n)
    i = 0
    for each in s:
        i += (ord(each)-ord('0'))**2
    return i
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        s=[n]
        i = happy(n)
        while i not in s:
            s.append(i)
            i = happy(i)
            
        if i==1:
            return True
        else:
            return False
            
            
            
