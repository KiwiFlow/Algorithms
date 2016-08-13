class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        record = [0 for i in range(26)]
        for i in magazine:
            record[ord(i)-ord('a')]+=1
        for j in ransomNote:
            if record[ord(j)-ord('a')]>0:
                record[ord(j)-ord('a')]-=1
            else:
                return False
        return True
                
        
