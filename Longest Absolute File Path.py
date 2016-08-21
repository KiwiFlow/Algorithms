class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        result = 0
        i = 0
        s = []
        while i<len(input):
            level = 1
            if input[i]== '\n':
                i+=1
            while input[i] == '\t':
                i+=1
                level+=1
        
            while len(s)+1>level:
                s.pop()
                
            if s:
                s.append(s[-1])
            else:
                s.append(0)
                
            isFile = False
            
            while i<len(input) and input[i]!='\n':
                if input[i]=='.':
                    isFile = True
                s[-1]+=1
                i+=1
                
            if isFile:
                result = max(result,s[-1])
                s.pop()
            else:
                s[-1]+=1 # add '/'
                
        return result
