class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        res = []
        for i in xrange(len(input)):
            if input[i] in ['+','-','*']:
                left = self.diffWaysToCompute(input[:i])
                right = self.diffWaysToCompute(input[i+1:])
                for l in left:
                    for r in right:
                        if input[i] == '+':
                            res.append(l+r)
                        elif input[i] == '-':
                            res.append(l-r)
                        else:
                            res.append(l*r)
        if res:
            return sorted(res)
        else:
            return [int(input)]
                        
