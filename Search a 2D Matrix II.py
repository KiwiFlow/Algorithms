class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = 0
        n = len(matrix[0])-1
        while m<len(matrix) and n>=0:
            if matrix[m][n] == target:
                return True
            elif matrix[m][n] > target:
                n-=1
            else:
                m+=1
        return False
        
        
