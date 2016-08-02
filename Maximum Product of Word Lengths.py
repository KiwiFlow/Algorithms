class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        ans = 0
        bits = [0 for i in range(len(words))]
        for i in range(len(words)):
            t = words[i]
            for k in t:
                bits[i] |= 1<<(ord(k)-ord('a'))
        for i in range(len(words)):
            for j in range(i,len(words),1):
                if bits[i]&bits[j] == 0:
                    ans = max(ans,len(words[i])*len(words[j]))
                    
        return ans
            
       
                
