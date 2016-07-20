class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        ret=''
        while n>0:
            a,b=n/26,n%26
            if b==0:
                a-=1
                ret = 'Z'+ret
            else:
                ret = chr(ord('A')+b-1)+ret
            n = a
        return ret
"""
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
"""
