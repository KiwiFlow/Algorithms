class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        for i in range(len(board)):
            for j in range(len(board[i])):
                lives = 0
                neighbors = [(i-1,j-1),(i-1,j),(i-1,j+1),(i,j-1),(i,j+1),(i+1,j-1),(i+1,j),(i+1,j+1)]
                for each in neighbors:
                    if each[0]>=0 and each[0]<len(board) and each[1]>=0 and each[1]<len(board[i]) and board[each[0]][each[1]]%2!=0:
                        lives+=1
                if board[i][j]==0 and lives!=3:
                    board[i][j]=2
                elif board[i][j]==1 and (lives==2 or lives==3):
                    board[i][j]=3
                    
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j]==2 or board[i][j]==3:
                    board[i][j] -=2
                else:
                    if board[i][j]==0:
                        board[i][j]=1
                    else:
                        board[i][j]=0
        
                    
                        
