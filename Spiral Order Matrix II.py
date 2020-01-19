#Author:Ahmed_Abd_Al_Mowla

class Solution:
	# @param A : integer
	# @return a list of list of integers
    a=0
    out=[]
    vis=[]
    def vaild(x,y):
        if (Solution.a<x or Solution.a<y)or(x<0 or y<0):
            return True
        return False
    val=0
    def DFS(x,y):
        if Solution.vaild(x,y)or Solution.vis[x][y]:
            return
        Solution.vis[x][y]=True
        if y==0:
            Solution.DFS(x-1,y)
        Solution.DFS(x,y+1)
        Solution.DFS(x+1,y)
        Solution.DFS(x,y-1)
        Solution.DFS(x-1,y)
        #print(x," * ",y)
        if x<  Solution.a and y<  Solution.a:
            Solution.out[x][y]=Solution.val
            Solution.val-=1
        return
    
    def generateMatrix(self, A):
        Solution.a=A
        for i in range(A):
            z=[]
            for j in range(A):
                z.append(j)
            Solution.out.append(z)
           
        for i in range(A+1):
            zz=[]
            for j in range(A+1):
                zz.append(False)
            Solution.vis.append(zz)
        Solution.val=A*A
        Solution.DFS(0,0)
        return Solution.out
    

aa=Solution()

z=aa.generateMatrix(4)

z
