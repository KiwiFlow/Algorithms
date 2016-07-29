class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        m = len(dungeon)
        n = len(dungeon[0])
        
        dp = [[0 for j in range(n)] for i in range(m)]
        
        for j in range(n-1,-1,-1):
            for i in range(m-1,-1,-1):
                if i == m-1 and j == n-1 :
                    if dungeon[i][j]>=0:
                        dp[i][j]=1
                    else:
                        dp[i][j] = abs(dungeon[i][j])+1
                else:
                    if i+1 < m and j+1 == n:
                        if dungeon[i][j]>=0:
                            dp[i][j] = max(1,dp[i+1][j] - dungeon[i][j])
                        else:
                            dp[i][j] = dp[i+1][j] + abs(dungeon[i][j])
                    if i+1==m and j+1 < n:
                        if dungeon[i][j]>=0:
                            dp[i][j] = max(1,dp[i][j+1] - dungeon[i][j])
                        else:
                            dp[i][j] = dp[i][j+1] + abs(dungeon[i][j])
                    if i+1<m and j+1<n:
                        if dungeon[i][j]>=0:
                            dp[i][j] = max(1,min(dp[i][j+1],dp[i+1][j])-dungeon[i][j])
                        else:
                            dp[i][j] = min(dp[i][j+1],dp[i+1][j])+abs(dungeon[i][j])
                            
        return dp[0][0]
                        
                
                
