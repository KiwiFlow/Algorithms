class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.in_s = []
        self.out_s = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.in_s.append(x)
        

    def pop(self):
        """
        :rtype: nothing
        """
        if  self.out_s:
            self.out_s.pop()
        else:
            while self.in_s:
                self.out_s.append(self.in_s[-1])
                self.in_s.pop()
            self.out_s.pop()
        

    def peek(self):
        """
        :rtype: int
        """
        if self.out_s:
            return self.out_s[-1]
        else:
            return self.in_s[0]
        

    def empty(self):
        """
        :rtype: bool
        """
        if self.in_s==[] and self.out_s==[]:
            return True
        else:
            return False
            
