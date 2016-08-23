
class BinaryIndexedTree:
	def __init__(self,nums):
		self.lowbits = [0 for i in range(len(nums)+1)]
		self.c = [0 for i in range(len(nums)+1)]
		for i in range(1,len(self.lowbits),1):
			self.lowbits[i] = i&(-i)
		
		for i in range(1,len(self.c),1):
			for j in range(i-self.lowbits[i]+1,i+1,1):
				self.c[i] += nums[j-1]
				
		print self.lowbits
		print self.c
		
	def add(self,i,delta):
		m = i+1 
		while m<len(self.c):
			self.c[m] += delta
			m += self.lowbits[m]
		
	def query_sum(self,i,j): 
		m = j+1
		sm=sn=0
		while m>=1:
			sm+=self.c[m]
			m = m-self.lowbits[m]
		while i>=1:
			sn+=self.c[i]
			i = i-self.lowbits[i]
		return sm-sn
		
s = BinaryIndexedTree([0,1,2,3,4,5,6,7,8,9,10])
print s.query_sum(0,10),s.query_sum(2,8),s.query_sum(5,5),s.query_sum(1,6)
s.add(0,3)
s.add(4,2)
s.add(5,5)
print s.query_sum(0,10),s.query_sum(2,8),s.query_sum(5,5),s.query_sum(1,6)
			
		
		
