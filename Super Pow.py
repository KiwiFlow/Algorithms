class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        result = 1
        for i in range(len(b)-1,-1,-1):
            result = result * a**b[i] % 1337
            a = a**10 % 1337
        return result
