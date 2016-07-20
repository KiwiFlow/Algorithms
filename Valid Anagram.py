class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s)!=len(t):
            return False
        record = [0 for i in range(26)]
        for each in s:
            record[ord(each)-ord('a')] +=1
        for each in t:
            record[ord(each)-ord('a')]-=1
        flag = True
        for each in record:
            if each != 0:
                flag=False
                break
        return flag
        
"""
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
"""
