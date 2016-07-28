class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs)==0:
            return ""
        elif len(strs)==1:
            return strs[0]
        left = self.longestCommonPrefix(strs[0:len(strs)/2])
        right = self.longestCommonPrefix(strs[len(strs)/2:len(strs)])
        if len(left)==0 or len(right)==0:
            return ""
        else:
            i=0
            ans=""
            while i<min(len(left),len(right)) and left[i] == right[i]:
                ans+=left[i]
                i+=1
            return ans
