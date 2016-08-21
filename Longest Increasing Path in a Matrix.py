class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        self.memory = [ [-1 for j in range(len(matrix[0]))] for i in range(len(matrix))]
        result = 0
        
       
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                result = max(result,self.longest(matrix,i,j))
                #print i,j,result
        return result
    
    def longest(self,matrix,i,j):
        if self.memory[i][j] != -1:
            return self.memory[i][j]
        else:
            result = 0
            canInc = False
            if i-1>=0 and matrix[i-1][j] > matrix[i][j]:
                result = max(result,self.longest(matrix,i-1,j)+1)
                canInc = True
            if j-1>=0 and matrix[i][j-1] > matrix[i][j]:
                result = max(result,self.longest(matrix,i,j-1)+1)
                canInc = True
            if i+1<len(matrix) and matrix[i+1][j] > matrix[i][j]:
                result = max(result,self.longest(matrix,i+1,j)+1)
                canInc = True
            if j+1<len(matrix[0]) and matrix[i][j+1] > matrix[i][j]:
                result = max(result,self.longest(matrix,i,j+1)+1)
                canInc = True
            if not canInc:
                self.memory[i][j]=1
            else:
                self.memory[i][j]=result
            return self.memory[i][j]
            
        
                
        
        
        
