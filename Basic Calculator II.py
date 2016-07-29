class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        op_c = [[-1,-1,-1,-1,1],[1,1,-1,-1,1],[1,1,1,1,1],[1,1,1,1,1],[-1,-1,-1,-1,0]]
        op_h = {'+':0,'-':1,'*':2,'/':3,'#':4}
        op_s = ['+','-','*','/','#',' ']
        
        ss = s+'#'
        op = ['#']
        data = []
        
        i = 0
        
        while i < len(ss) or op:
            while i < len(ss) and ss[i]==' ':
                i+=1
            if i<len(ss) and ss[i] not in op_s:
                d = ''
                while i<len(ss) and ss[i] not in op_s:
                    d = d+ss[i]
                    i+=1
                data.append(int(d))
            elif i<len(ss):
                if op_c[op_h[op[-1]]][op_h[ss[i]]] == -1:
                    op.append(ss[i])
                    i+=1
                elif op_c[op_h[op[-1]]][op_h[ss[i]]] == 0:
                    op.pop()
                    i+=1
                elif op_c[op_h[op[-1]]][op_h[ss[i]]] == 1:
                    if op[-1] == '+':
                        c = data[-2] + data[-1]
                    elif op[-1] == '-':
                        c = data[-2] - data[-1]
                    elif op[-1] == '*':
                        c = data[-2] * data[-1]
                    elif op[-1] == '/':
                        c = data[-2] / data[-1]
                    data.pop()
                    data.pop()
                    data.append(c)
                    op.pop()
        return data[0]
