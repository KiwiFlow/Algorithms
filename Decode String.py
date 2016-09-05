class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s=="":
            return ""
        elif s[0].isalpha():
            i=0
            while i<len(s) and s[i].isalpha():
                i+=1
            return s[:i]+self.decodeString(s[i:])
        elif s[0]=='[':
            return ""
        elif s[0].isdigit():
            num = ''
            i = 0
            while s[i].isdigit():
                num = num+s[i]
                i+=1
            j=i
            stack = []
            while i<len(s):
                if s[i]=='[':
                    stack.append(i)
                elif s[i]==']':
                    if len(stack)==1:
                        return int(num)*self.decodeString(s[j+1:i])+self.decodeString(s[i+1:])
                    else:
                        stack.pop()
                i+=1
        
            
