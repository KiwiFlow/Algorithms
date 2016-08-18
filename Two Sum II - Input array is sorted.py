class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        r = []
        j=len(numbers)-1
        t=0
        while j>t and numbers[t]+numbers[j] < target:
            t+=1
        for i in range(t,len(numbers)):
            #print i,j
            while j>i and numbers[i]+numbers[j]>target:
                j-=1
            if j==i:
                break
            elif numbers[i]+numbers[j]==target:
                r = [i+1,j+1]
                return r
            else:
                j+=1
        return None
           
