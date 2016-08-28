class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        letter = [0 for i in xrange(26)]
        for each in s:
            letter[ord(each)-ord('a')]+=1
        for each in t:
            letter[ord(each)-ord('a')]-=1
        for i in xrange(len(letter)):
            if letter[i]==-1:
                return chr(i+ord('a'))
        
