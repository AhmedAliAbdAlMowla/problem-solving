/*                                        problim link:http://codeforces.com/contest/977/submission/39037454
                                          Author:Ahmed_Abd_Al_Mowla*/
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
 
using namespace std;
 
#define loop(i,n)   for(i=0;i<n;i++)
#define GCC_go ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define stop system("pause");
typedef  long long ll;
template <class T>inline void arin(T* st, T* nd){while(st<nd)cin>>*st++;}
 
 
 
 
int n,e;
vector<vector<int> >adj;
bool vis[200002],what;
int  d[200002];
 
int sum=0,nd=0;
 
int cy=0;
void dfs(int node){
int i;	
vis[node]=true;
 
if (d[node]!=2)
what=false;
//cout<<"#  "<<what<<endl;
loop(i,adj[node].size()){
	
	if(!vis[adj[node][i]]){
	
		dfs(adj[node][i]);
	}
	
}	}
 
 
 
 
void couneccted(){
	
	int ans=0,i;
	
	loop(i,n){
			
	
	if(!vis[i]){
		what=true;
	
		dfs(i);
			cy+=what;
			
	
}
 
	
	}
}
	
 
 
int main(){
	                           GCC_go
	
 
cin>>n>>e;
 
adj.clear();
adj.resize(n+1);
 
int i,x,y;
 
loop(i,e){
	cin>>x>>y;
	adj[x].push_back(y);
	adj[y].push_back(x);
	d[x]++;
	d[y]++;}
	couneccted();
	cout<<cy;
	
	
}
 
