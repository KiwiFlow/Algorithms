"""
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> euqations, vector<double>& values, vector<pair<string, string>> query . where equations.size() == values.size(),the values are positive. this represents the equations.return vector<double>. . 
The example above: equations = [ ["a", "b"], ["b", "c"] ]. values = [2.0, 3.0]. queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
"""
class Solution(object):
    def calcEquation(self, equations, values, query):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type query: List[List[str]]
        :rtype: List[float]
        """
        self.d = {}
        for i in xrange(len(equations)):
            if equations[i][0] in self.d:
                self.d[equations[i][0]][equations[i][1]]=values[i]
            else:
                self.d[equations[i][0]]= {equations[i][1]:values[i]}
                
            if equations[i][1] in self.d:
                self.d[equations[i][1]][equations[i][0]]=1.0/values[i]
            else:
                self.d[equations[i][1]]= {equations[i][0]:1.0/values[i]}

                
                
        #print self.d
        res = []
        for each in query:
            a = self.Eval(each,[])
            #print each,a
            if a[0] == False:
                res.append(-1.0)
            else:
                res.append(a[1])
        return res
    
    def Eval(self,query,record):
        
        if query[0] in self.d and query[1] in self.d:
            if query[0]==query[1]:
                return True,1.0
            elif query[1] in self.d[query[0]]:
                return True,self.d[query[0]][query[1]]
            else:
                s = self.d[query[0]].keys()
                record.append(query[0])
                b = query[0]
                for each in s:
                    
                    if each not in record:
                        query[0] = each
                        ret = self.Eval(query,record)
                        if ret[0]==True:
                            return True,self.d[b][each]*ret[1]
                return False,-1.0
        else:
            return False,-1.0
        
            
            
                
        
