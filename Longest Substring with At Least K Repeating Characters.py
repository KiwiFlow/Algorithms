class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if len(s) < k:
            return 0
        record = [0 for i in xrange(26)]
        for each in s:
            record[ord(each)-ord('a')]+=1
        minV = len(s)+1
        minC = ''
        for i in xrange(len(record)):
            if record[i]!=0 and record[i]<minV:
                minV = record[i]
                minC = chr(i+ord('a'))
        if minV>=k:
            return len(s)
        else:
            return max(self.longestSubstring(p,k) for p in s.split(minC))
