class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        i = 0
        j = 0
        res = False
    
        while i<len(s) and j<len(t):
            while i<len(s) and j<len(t) and s[i]!=t[j]:
                j+=1
            if j<len(t):
                i+=1
                j+=1
            
        if i==len(s):
            return True
        else:
            return False
        
            
        
