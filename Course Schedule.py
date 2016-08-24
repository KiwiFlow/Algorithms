class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
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
                for key in edges:  
                    if mark in edges[key]:  
                        edges[key].remove(mark)  
            else:  
                return False
        return True
                
                
    
        
