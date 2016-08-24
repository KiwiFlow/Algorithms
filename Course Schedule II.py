class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        
        return self.topologicSort(numCourses,prerequisites)
        
        
        
    def topologicSort(self,numCourses,prerequisites):
        edges = {}
        for each in prerequisites:
            if each[0] in edges:
                if each[1] not in edges[each[0]]:
                    edges[each[0]].append(each[1])
            else:
                edges[each[0]] = [each[1]]
                
        for i in range(numCourses):
            if i not in edges:
                edges[i] = []
        res = []
        for i in range(numCourses):  
            isOk = False #是否可以继续  
            mark = -1
            for key in edges:  
                if not edges[key]:  
                    mark=key  
                    isOk=True  
                    del edges[key]  
                    break
            if isOk:  
                res.append(mark)
                for key in edges:  
                    if mark in edges[key]:  
                        edges[key].remove(mark)  
            else:  
                return []
        return res
