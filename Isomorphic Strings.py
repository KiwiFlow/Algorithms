class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        flag = True
        record={}
        for i in range(len(s)):
            if s[i] in record.keys():
                if t[i]!=record[s[i]]:
                    flag=False
                    return flag
            else:
                record[s[i]]=t[i]
                
        
        record_1={}
        for i in range(len(t)):
            if t[i] in record_1.keys():
                if s[i]!=record_1[t[i]]:
                    flag=False
                    return flag
            else:
                record_1[t[i]]=s[i]
                
       
        
        return flag
        
