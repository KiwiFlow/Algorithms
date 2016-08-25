class NumMatrix(object):
    def __init__(self, matrix):
        """
        initialize your data structure here.
        :type matrix: List[List[int]]
        """
        self.colsum = [[0 for j in xrange(len(matrix[0]))] for i in xrange(len(matrix))]
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[0])):
                if i==0:
                    self.colsum[i][j] = matrix[i][j]
                else:
                    self.colsum[i][j] = self.colsum[i-1][j]+matrix[i][j]
            
        

    def sumRegion(self, row1, col1, row2, col2):
        """
        sum of elements matrix[(row1,col1)..(row2,col2)], inclusive.
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        s = 0
        for x in xrange(col1,col2+1):
            if row1==0:
                s=s+self.colsum[row2][x]
            else:
                s=s+self.colsum[row2][x]-self.colsum[row1-1][x]
            
        return s
        


# Your NumMatrix object will be instantiated and called as such:
# numMatrix = NumMatrix(matrix)
# numMatrix.sumRegion(0, 1, 2, 3)
# numMatrix.sumRegion(1, 2, 3, 4)
