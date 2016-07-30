class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        if not envelopes:
            return 0
        envelopes = sorted(envelopes,key = lambda item:(item[0],-item[1]))
        dp = [envelopes[0][1]]
        
        for i in range(1,len(envelopes),1):
            if envelopes[i][1] > dp[-1]:
                dp.append(envelopes[i][1])
            else:
                left = 0
                right = len(dp)-1
                while left <= right:
                    mid = left + (right - left)/2
                    if envelopes[i][1] <= dp[mid] and (mid==0 or (mid > 0 and envelopes[i][1]>dp[mid-1])):
                        dp[mid]=envelopes[i][1]
                        break
                    elif envelopes[i][1] > dp[mid]:
                        left = mid+1
                    else:
                        right = mid-1
                        
        return len(dp)
