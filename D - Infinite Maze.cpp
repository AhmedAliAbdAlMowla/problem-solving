 /*                                         problim link:http://codeforces.com/contest/197/submission/39209024
                                            Author:Ahmed_Abd_Al_Mowla*/
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define loop(i,n)   for(i=0;i<n;i++)
#define GCC_go ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define stop system("pause");
typedef  long long ll;
template <class T>inline void arin(T* st, T* nd){while(st<nd)cin>>*st++;}
 
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};
 
bool fin=false,ty=false;
char mem[1501][1501];
bool vis[1501][1501];
int bigvis[1501][1501][3];
int n,m;
int proses(int xdx,int q){if(q==1)return (xdx+n*1500)%n;
else return (xdx+m*1500)%m;
}
 
 
void dfs(int i,int j){
	
	int inew=proses(i,1);
	int jnew=proses(j,2);
	
//	cout<<mem[i][j]<<endl;
	if(mem[inew][jnew]=='#')
	return ;
      if(vis[inew][jnew]){
	if(bigvis[inew][jnew][1]!=i||bigvis[inew][jnew][2]!=j)fin=true;
				return;}
 
	bigvis[inew][jnew][1]=i;bigvis[inew][jnew][2]=j;
	vis[inew][jnew]=1;
	
	for(int k=0;k<4;k++){
	
		int tox=i+dx[k];
		int toy=j+dy[k];
		dfs(tox,toy);
	}
	
	
}
 
 
 
 
 
string solve(int i,int j){	
memset(bigvis,-1,sizeof(bigvis));
 
	dfs(i,j);
 
	return (fin)?"Yes":"No";
	
}
 
 
int main(){int p1,p2;
    //cout<<-1%5;
	int i,j;
	cin>>n>>m;
	loop(i,n)
	loop(j,m){
	cin>>mem[i][j];
	if(mem[i][j]=='S'){
	  p1=i;p2=j;
    }
	}
	cout<<solve(p1,p2);
	
	
	
	
	
	
	
	
}
