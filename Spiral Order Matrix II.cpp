                                                 /*Author:Ahmed_Abd_Al_Mowla*/
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
bool cmd(pair<int, int>a, pair<int, int>b) {return a.F<b.F;}
 
int a;


int out[1000][1000];
    bool vis[1000][1000];


bool valid(int x,int y){
    if(((a<=x)||a<=y)||(x<0||y<0))
    return true;
return false;
}
int val;

void DFS(int x,int y){
    
    if(valid(x,y)||(vis[x][y]))
    return;
    
    vis[x][y]=1;
    //cout<<x<<y<<endl;
    if(y==0)
    DFS(x-1,y);
    DFS(x,y+1);
    DFS(x+1,y);
    DFS(x,y-1);    
    DFS(x-1,y);

        
        out[x][y]=val;
        val--;
    return;
}


vector<vector<int> > generateMatrix(int A) {
    val=A*A;
     DFS(0,0);
     vector<vector<int> >ans(A,vector<int>(A));
      for(int i=0;i<A;i++){
    for(int j=0;j<A;j++){
     
    ans[i][j]=out[i][j];}
    }
    return ans;
    
}

int main(){
	

	cin>>a;
	vector<vector<int> >x;
	x=generateMatrix(a);
	
	for(int i=0;i<a;i++){
	for(int j=0;j<a;j++)
	cout<<x[i][j]<<" ";
	cout<<endl;}
	
	
}
