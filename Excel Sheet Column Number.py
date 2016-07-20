class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = ord(s[0])-ord('A')+1
        for i in range(1,len(s)):
            n = n*26+ord(s[i])-ord('A')+1
        return n
            
        
"""
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
"""
