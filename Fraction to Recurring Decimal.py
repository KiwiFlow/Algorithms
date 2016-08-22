class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if denominator==0:
            return "NaN"
        if numerator == 0:
            return '0'
        isPositive = True
        if numerator*denominator < 0:
            isPositive = False
        numerator = abs(numerator)
        denominator = abs(denominator)
        
        if numerator % denominator == 0:
            if isPositive:
                return str(numerator / denominator)
            else:
                return '-'+str(numerator / denominator)
        else:
            result = str(numerator / denominator)+'.'
            i = (numerator % denominator)*10
            r = {}
            s = ''
            loopIndex = 0
            while (i not in r) and i!=0:
                s += str(i/denominator)
                r[i] = [i%denominator *10,loopIndex]
                loopIndex += 1
                i = r[i][0]
            if i!=0:
                s = s[0:r[i][1]]+'('+s[r[i][1]:]+')'
            result += s
           
            if isPositive:
                return result
            else:
                return '-'+result
            
        
        
