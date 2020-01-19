/*
                        2015-2016 ACM-ICPC, NEERC, Northern Subregional Contest
                                Author:Ahmed_Abd_Al_Mowla*/
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
bool cmd(pair<int, int>a, pair<int, int>b) {return (a.S < b.S);}
int n,m;
int mem[101][101];
 
 
bool win(int i,int j,int d){
    if(d==1)
    return (j==(m-1));
    else if(d==2)return (j==0);
    else if(d==3)
        return (i==(n-1));
    else return (i==0);
}
 
bool right(int i,int j,int val){
   //  cout<<mem[i][j]<<" ";
    if(win(i,j,1))
        return true;
   //cout<<mem[i][j]<<"###"<<endl;
    if(mem[i][j+1]<val)
       return  right(i,j+1,val);
    return false;
    
    
    
}
 
bool left(int i,int j,int val){
    
    
     
    if(win(i,j,2))
        return true;
    //cout<<mem[i][j]<<"###"<<endl;
    if(mem[i][j-1]<val)
       return  left(i,j-1,val);
    return false;
    
    
    
    
}
 
bool down(int i,int j,int val){
    
    
     
    if(win(i,j,3))
        return true;
   // cout<<mem[i][j]<<"###"<<endl;
    if(mem[i+1][j]<val)
       return  down(i+1,j,val);
    return false;
    
    
    
    
}
bool up(int i,int j,int val){
    
    if(win(i,j,4))
        return true;
  //  cout<<mem[i][j]<<"###"<<endl;
    if(mem[i-1][j]<val)
       return up(i-1,j,val);
    return false;
    
    
    
    
    
}
 
int count(){
    int ans=0,j;
     loop(i,n){
         
         for(j=0;j<m;j++)
     {
         if(right(i,j,mem[i][j]))ans++;
       
         if(left(i,j,mem[i][j]))ans++;
         
         if(down(i,j,mem[i][j]))ans++;
        
         if(up(i,j,mem[i][j]))ans++;
          // cout<<mem[i][j]<< "  "<<ans<<"\n";
     }
   
     }
    
     return ans;
    
    
}
 
int main(){
    
    freopen("lucky.in ","r",stdin);
   freopen("lucky.out ","w",stdout);
    
    cin>>n>>m;
    loop(i,n)
    loop(j,m)
    cin>>mem[i][j];
    
    
    cout<<count();
    
    
    
    
}
