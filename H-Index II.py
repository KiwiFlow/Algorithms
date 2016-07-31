class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        if not citations:
            return 0
        N = len(citations)
        if citations[0] >= N:
            return N
        if N==1 and citations[0]==0:
            return 0
            
            
        left = 0
        right = N-1
        while left<=right:
            mid = left + (right-left)/2
            if mid==0:
                if left == 0 and right ==0:
                    if citations[0]==0:
                        return 0
                    else:
                        return 1
                else:
                    if citations[0]==0 and citations[1]==0:
                        return 0
                    elif citations[0]==0:
                        return 1
                    elif citations[0]==1:
                        return 1
                    else:
                        return 2
                        
            if citations[N-mid] < mid:
                right = mid-1
            elif citations[N-mid]==mid:
                return mid
            else:
                if citations[N-mid-1] <= mid:
                    return mid
                else:
                    j=1
                    while j<=N-1-mid and citations[N-mid-j]>=mid+j:
                        j+=1
                    return mid+j-1
        return 0
