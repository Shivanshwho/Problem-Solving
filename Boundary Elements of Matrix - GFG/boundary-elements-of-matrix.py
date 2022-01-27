#User function Template for python3

class Solution:
	def BoundaryElements(self, matrix):
		# Code here
		m=len(matrix)
		n=len(matrix[0])
		list=[]
		for i in range(0,m):
		    for j in range(0,n):
		        if(i==0 or j==0 or i==m-1 or j==n-1):
		            list.append(matrix[i][j])
		            
		return list            
		         
		        

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		matrix = []
		for _ in range(n):
			matrix.append(list(map(int, input().split())))
		ob = Solution()
		ans = ob.BoundaryElements(matrix)
		for _ in ans:
			print(_ ,end = " ")
		print()

# } Driver Code Ends