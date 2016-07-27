class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = version1.split('.')
        v2 = version2.split('.')
        i=0
        while i<len(v1) and i<len(v2):
            if int(v1[i]) < int(v2[i]):
                return -1
            elif int(v1[i]) > int(v2[i]):
                return 1
            i+=1
        if i<len(v2):
            mark = True
            while i<len(v2):
                if int(v2[i])!=0:
                    return -1
                i+=1
        if i<len(v1):
            mark = True
            while i<len(v1):
                if int(v1[i])!=0:
                    return 1
                i+=1
        return 0
