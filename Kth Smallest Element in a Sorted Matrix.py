class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        indexs = [(matrix[i][0],(i,0)) for i in range(len(matrix))]
        heapq.heapify(indexs)
        ans = 0
        while k>0:
            t = heapq.heappop(indexs)
            if t[1][1] < len(matrix[0])-1:
                heapq.heappush(indexs,(matrix[t[1][0]][t[1][1]+1],(t[1][0],t[1][1]+1)))
            ans = t[0]
            k-=1
        return ans
            
            
        
