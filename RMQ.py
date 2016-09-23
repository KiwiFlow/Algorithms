class RMQ:
	def __init__(self,nums):
		#assert len(nums)>=2
		M = len(nums)
		N = 0
		while (1<<N) < M:
			N+=1
		
		self.d = [[0 for j in range(N)] for i in range(M)]
		for i in range(M):
			self.d[i][0] = nums[i]
		for j in range(1,N):
			for i in range(M):
				if i+(1<<(j-1))<=M:
					self.d[i][j] = min(self.d[i][j-1],self.d[i+(1<<(j-1))][j-1])
				
	def query(self,p,q):
		x = 0
		while 1<<(x+1) < q-p+1:
			x+=1
		return min(self.d[p][x],self.d[q-(1<<x)+1][x])
		
from random import shuffle
t = range(100)
shuffle(t)
s1 = RMQ(t)
print t[0:11]
print t[1:6]
print t[6:9]
print s1.query(0,10),s1.query(1,5),s1.query(6,8)
