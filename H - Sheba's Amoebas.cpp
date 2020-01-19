                                          /*problim link:http://codeforces.com/gym/101673/submission/39178153
                                          Author:Ahmed_Abd_Al_Mowla*/
#include<bits/stdc++.h>
using namespace std;
#define loop(i,n)   for(i=0;i<n;i++)
#define GCC_go ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define stop system("pause");
typedef  long long ll;
template <class T>inline void arin(T* st, T* nd){while(st<nd)cin>>*st++;}
 
const int dxx[]={1,-1,0,0,1,-1,-1,1};
const int dyy[]={0,0,1,-1,1,-1,1,-1};
 
 
int n,m;
char mem[101][101];
int vis[101][101];
 
 
bool valid(int i,int j){
	return (i>=n||i<0||j>=m||j<0);
}
 
 
 
void dfs(int i,int j){
	
	if(vis[i][j])
	return ;
	if(valid(i,j))
	return ;
	if(mem[i][j]=='.')
	return ;
	
	vis[i][j]=1;
	for(int k=0;k<8;k++)
	{
		int tox=i+dxx[k];
		int toy=j+dyy[k];
		dfs(tox,toy);
		
		}	
	
	
	}
 
int conected(){
	int i,j,c=0;
	
	loop(i,n)
	loop(j,m){
		
		if(!vis[i][j]&&mem[i][j]=='#'){
		                
		dfs(i,j);	
			c++;
			
		}
		}
	
	return c;}
 
 
int main(){
int i,j;
cin>>n>>m;
loop(i,n)
loop(j,m)
cin>>mem[i][j];
 
 
 
cout<<conected();	
	
	
	
}
/*
12 10 
.#####.... 
#.....#... 
#..#..#... 
#.#.#.#... 
#..#..#... 
.#...#.... 
..###..... 
......#... 
.##..#.#.. 
#..#..#... 
.##....... 
..........
 
 
*/
 
