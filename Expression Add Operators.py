#wa,无法处理乘法的优先级
class Solution(object):
    def gen(self,num):
        #产生任意的计算表达式
        if not num:
            return []
        result = []
        for i in range(1,len(num)+1,1):
            if i==len(num):
                result.append(num)
            elif i==1 and num[0]=='0':
                a = self.gen(num[1:])
                for each in a:
                    result.append('0+'+each)
                    result.append('0-'+each)
                    result.append('0*'+each)
                break
            else:
                a = self.gen(num[i:])
                for each in a:
                    result.append(num[:i]+'+'+each)
                    result.append(num[:i]+'-'+each)
                    result.append(num[:i]+'*'+each)
        return result
        
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        if not num:
            return []
        result = []
        for i in range(1,len(num)+1,1):
            x = int(num[:i])
            if i==len(num): #不划分
                if x==target:
                    result.append(num)
            elif i==1 and x==0:#划分 第一个字符为0
                a = self.addOperators(num[i:],target)
                for each in a:
                    result.append('0+'+each)
                b = self.addOperators(num[i:],-target)
                for each in b:
                    result.append('0-'+each)
                if target==0:
                    c = self.gen(num[i:])
                    for each in c:
                        result.append('0*'+each)
                break
            else:#划分 第一个字符不为0
                a = self.addOperators(num[i:],target-x)
                for each in a:
                    result.append(num[:i]+'+'+each)
                b = self.addOperators(num[i:],x-target)
                for each in b:
                    result.append(num[:i]+'-'+each)
                if target%x==0:
                    c = self.addOperators(num[i:],target/x)
                    for each in c:
                        result.append(num[:i]+'*'+each)
        return sorted(result)
