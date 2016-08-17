def compare(i,j):
    lenI = len(str(i))
    lenJ = len(str(j))
    
    
    if i*pow(10,lenJ)+j<j*pow(10,lenI)+i:
        return -1
    elif i*pow(10,lenJ)+j>j*pow(10,lenI)+i:
        return 1
    else:
        return 0
class Solution:
    # @param {integer[]} nums
    # @return {string}
    def largestNumber(self, nums):
        nums.sort(cmp=compare,reverse=True)
        s = ''
        for each in nums:
            if not(s and s[0]=='0'):
                s = s+str(each)
        return s
        
