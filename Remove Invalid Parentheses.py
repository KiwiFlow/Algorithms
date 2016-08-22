class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        
        from collections import deque
        d = deque()
        d.append(s)
        isVisited = {s:None}
        result = []
        while d:
            i = d.popleft()
            #print i
            if self.isValid(i):
                result.append(i)
            elif not result:
                for j in range(len(i)):
                    if i[j]=='(' or i[j]==')':
                        k = i[:j]+i[j+1:]
                        if k not in isVisited:
                            d.append(k)
                            isVisited[k] = None
        return sorted(result,reverse=True)
            
    def isValid(self,s):
        count = 0
        for each in s:
            if count<0:
                break
            if each == '(':
                count += 1
            elif each == ')':
                count -= 1
        return count==0
            
        
