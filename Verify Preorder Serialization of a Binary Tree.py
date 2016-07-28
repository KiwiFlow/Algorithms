class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        i = preorder.split(',')
        j = 0
        s = []
        while j<len(i):
            s.append(i[j])
            while len(s)>2 and s[-1]=='#' and s[-2]=='#' and s[-3]!='#':
                s.pop()
                s.pop()
                s.pop()
                s.append('#')
            j+=1
        
        if s==['#']:
            return True
        return False
                
            
        
    
        
