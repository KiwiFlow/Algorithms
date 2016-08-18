class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        a = [0,0]
        b = [0,0]
        for each in nums:
            if a[1]!=0 and b[1]!=0 and each!=a[0] and each!=b[0]:
                a[1]-=1
                b[1]-=1
            elif a[1]!=0 and each==a[0]:
                a[1]+=1
            elif b[1]!=0 and each==b[0]:
                b[1]+=1
            elif a[1]==0:
                a[0],a[1] = each,1
            else:
                b[0],b[1] = each,1
        a[1]=0
        b[1]=0
        for each in nums:
            if each==a[0]:
                a[1]+=1
            elif each==b[0]:
                b[1]+=1
                   
        r = []
        import math
        if a[1] > math.floor(len(nums)/3):
            r.append(a[0])
        if b[1] > math.floor(len(nums)/3):
            r.append(b[0])
 
        return r
                
