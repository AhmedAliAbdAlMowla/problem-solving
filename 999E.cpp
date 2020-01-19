/*                      problim link: http://codeforces.com/contest/999/submission/40873299
                        Author:Ahmed_Abd_Al_Mowla
*/
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define loop(i,n)   for(int i=0;i<(int)(n);i++)
#define GCC_go ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define stop system("pause");
#define F first
#define S second
typedef long long ll;
#define fx fixed
#define setp(n) setprecision(n)
#define PI 3.14159
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;
template <class T>inline void arin(T* st, T* nd) {
    while (st < nd)cin>>*st++;
}
 
int di[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dj[] = {0, 0, 1, -1, 1, -1, -1, 1};
int diK[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int djK[] = {-1, 1, 2, 2, 1, -1, -2, -2};
bool cmd(pair<int, int>a, pair<int, int>b) {return (a.S > b.S);}
 
int n,m,k;
vector<vector<int> > adj;
vector<bool>vis;
vector<pair<int,int> > vis2;
int ans;
 
stack<int>saver;
 
void DFS(int NODE){
    
    
    vis[NODE]=1;
    
    for(int i=0;i<adj[NODE].size();i++){
        
        if(!vis[adj[NODE][i]])
            DFS(adj[NODE][i]);
        
    }
    
    
   
  
}
 
void conect(){
    
   
  vis=vector<bool>(n+1,false);
    DFS(k);
    
    
   
    
    
    
    
    for(int i=1;i<=n;i++)
        if(!vis[i]){ //cout<<i<<" ---> ";
          /*  loop(j,adj[i].size())
            {
                cout<<adj[i][j]<<" ";
            }*/
           // cout<<endl;
            saver.push(i);
            DFS(i);}
    
    
    vis=vector<bool>(n+1,false);
         DFS(k);
         
         int sz=saver.size();
         loop(i,sz){
             if(!vis[saver.top()]){
             ans++;
             DFS(saver.top());}
             saver.pop();
             
         }
        
    
    
    
    
}
 
 
int main(){
    
    cin>>n>>m>>k;
    adj.resize(n+1);
  //  vis.resize(n+1);
  
    ll a,b;
    loop(i,m){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    
    conect();
 
    cout<<ans;
    
    
    
}
/*
7  7 1
        1 2
        2 3
        3 1
        1 4
        4 3
        5 6
        5 7
 */
