class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        N = len(citations)
        citations.sort()
        i = 1
        while i<=N:
            if i==N and citations[N-i] >= i:
                return i
            elif citations[N-i] >= i and citations[N-i-1] <= i:
                return i
            i+=1
        return 0
