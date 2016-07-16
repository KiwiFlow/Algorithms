class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.record = [[-1 for x in range(n+1)] for y in range(n+1)] 
        return self.rangeVal(1,n)
        
    def rangeVal(self,i,j):
        if self.record[i][j]==-1:
            if i==j:
                self.record[i][j]=0
            elif i==j-1:
                self.record[i][j]=i
            elif i==j-2:
                self.record[i][j]=i+1
            else:
            # 枚举猜想的值(k),k从i到j
                min_val = min(i+self.rangeVal(i+1,j),j+self.rangeVal(i,j-1))
                for k in range(i+1,j):
                    min_val = min(min_val,k+max(self.rangeVal(i,k-1),self.rangeVal(k+1,j)))
                self.record[i][j]=min_val
        return self.record[i][j]
        
"""
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
"""
