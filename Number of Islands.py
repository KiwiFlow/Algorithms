class Solution(object):
    def scan(self,grid,rows,cols,unv,i,j):
        unv[i][j]=1
        if j+1<cols and grid[i][j+1]=='1' and unv[i][j+1]==0:
            self.scan(grid,rows,cols,unv,i,j+1)
        if i+1<rows and grid[i+1][j]=='1' and unv[i+1][j]==0:
            self.scan(grid,rows,cols,unv,i+1,j)
        if j-1>=0 and grid[i][j-1]=='1' and unv[i][j-1]==0:
            self.scan(grid,rows,cols,unv,i,j-1)
        if i-1>=0 and grid[i-1][j]=='1' and unv[i-1][j]==0:
            self.scan(grid,rows,cols,unv,i-1,j)
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
        rows = len(grid)
        cols = len(grid[0])
        unv = [[0 for j in range(cols)]for i in range(rows)]
        count = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j]=='1' and unv[i][j]==0:
                    self.scan(grid,rows,cols,unv,i,j)
                    count+=1
        return count
                    
        
