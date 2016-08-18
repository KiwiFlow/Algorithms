"""
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
"""
class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        if len(s) < 10:
            return []
        result = []
        i = s[0:10]
        pre = 0
        h = {'A':1,'C':2,'G':3,'T':4}
        for each in i:
            pre = pre*10 + h[each]
        r = {pre:1}
            
        for k in range(1,len(s)-10+1):
            #print r
            v = (pre%(pow(10,9))) * 10 + h[s[k+9]]
            if v not in r:
                r[v] = 1
            elif r[v] == 1:
                result.append(s[k:k+10])
                r[v]+=1
            pre = v
        return result
