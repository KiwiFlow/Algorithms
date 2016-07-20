class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        h = [A,C,E,G]
        v = [B,D,F,H]
        h.sort()
        v.sort()
        if self.hasIntersection(A, B, C, D, E, F, G, H):
            return (C-A)*(D-B)+(G-E)*(H-F)-(h[2]-h[1])*(v[2]-v[1])
        else:
            return (C-A)*(D-B)+(G-E)*(H-F)
    def hasIntersection(self,A, B, C, D, E, F, G, H):
        h = not(E>=C or G<=A)
        v = not(F>=D or H<=B)
        return h and v
        
        
