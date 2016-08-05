"""
 MLE
class Solution(object):
    def canMeasureWater(self, x, y, z):
        isVisited = [[0 for j in range(y+1)] for i in range(x+1)]
        from collections import deque
        q = deque([(0,0)])
        isVisited[0][0]=1
        while q:
            cur = q.popleft()
            if cur[0]+cur[1]==z:
                return True
            if isVisited[0][cur[1]]==0:
                q.append((0,cur[1]))
                isVisited[0][cur[1]]=1
            elif isVisited[cur[0]][0]==0:
                q.append((cur[0],0))==0
                isVisited[cur[0]][0]=1
                
            if isVisited[x][cur[1]]==0:
                q.append((x,cur[1]))
                isVisited[x][cur[1]]=1
            elif isVisited[cur[0]][y]==0:
                q.append((cur[0],y))
                isVisited[cur[0]][y]=1
                
            if cur[0]>=(y-cur[1]) and isVisited[cur[0]-y+cur[1]][y]==0:
                q.append((cur[0]-y+cur[1],y))
                isVisited[cur[0]-y+cur[1]][y]=1
            if cur[0]<(y-cur[1]) and isVisited[0][cur[1]+cur[0]]==0:
                q.append((0,cur[0]+cur[1]))
                isVisited[0][cur[1]+cur[0]]=1
                
            if cur[1]>=(x-cur[0]) and isVisited[x][cur[1]-x+cur[0]]==0:
                q.append((x,cur[1]-x+cur[0]))
                isVisited[x][cur[1]-x+cur[0]]=1
            if cur[1]<(x-cur[0]) and isVisited[cur[0]+cur[1]][0]==0:
                q.append((cur[0]+cur[1],0))
                isVisited[cur[0]+cur[1]][0]
                
        return False
"""
