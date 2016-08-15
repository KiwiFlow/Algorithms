class Solution(object):
    def whoIsBigger(self,s1,s2,i,j):
            while i<len(s1) and j<len(s2):
                if s1[i] > s2[j]:
                    return True
                elif s1[i] < s2[j]:
                    return False
                else:
                    i+=1
                    j+=1
            return True
            
    def getMaxNumber(self,nums,k):
        s = []
        if k==0:
            return s
        else:
            s.append(nums[0])
        i=1
        while i<len(nums):
            if len(s) + len(nums)-i == k:
                s.append(nums[i])
            elif s and nums[i]>s[-1]:
                while s and nums[i]>s[-1] and len(s)+len(nums)-i>k:
                    s.pop()
                s.append(nums[i])
            elif len(s) < k:
                s.append(nums[i])
                
            i+=1
        return s
    
    def maxNumber(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        if k<=0:
            return []
        ret = 0
        rL = [0 for i in range(k)]
        for i in range(0,len(nums1)+1):
            if k-i>=0 and k-i<=len(nums2):
                s1 = self.getMaxNumber(nums1,i)
                s2 = self.getMaxNumber(nums2,k-i)
                s1.append(-1)
                s2.append(-1)
                p = 0
                q = 0
                ans = 0
                while s1 and s2 and (s1[p]!=-1 or s2[q]!=-1):
                    if self.whoIsBigger(s1,s2,p,q):
                        ans = ans*10 + s1[p]
                        p+=1
                    else:
                        ans = ans*10 + s2[q]
                        q+=1
                ret = max(ans,ret)
        for i in range(k):
            rL[i] = ret%10
            ret = ret/10
        rL.reverse()
        return rL
