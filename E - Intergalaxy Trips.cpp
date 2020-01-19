
                                        /*Author:Ahmed_Abd_Al_Mowla*/
#pragma GCC optimize ("O3")
#include"bits/stdc++.h"
//#include "MATHClass/Helper.hh"
using namespace std;
#define loop(i,n)   for(int i=0;i<(int)(n);i++)
#define GCC_go ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define stop system("pause");
#define F first
#define S second
#define fx fixed
#define setp(n) setprecision(n) 
#define OO 1e4
typedef  long long ll;
template <class T>inline void arin(T* st, T* nd){while(st<nd)cin>>*st++;}
 
class MATH{
 
                                       	public : MATH(){}
// ------------------------------------		
ll GCD(ll a, ll b) {
	return b == 0 ? a : GCD(b, a % b);
}
//-------------------------------------
ll LCM(ll i, ll j)
{
	return (i*j) / GCD(i, j);
}
//----------------------------------------
ll pows(ll n){return (1<<n);}
//----------------------------------------
int dig(ll n){
	int nu=0;
	while(n){
		nu+=n%10;
		n/=10;
	}
	return nu;}
//----------------------------------------
double sqrt3(double x){
return cbrt(x);}
};
ll sum=0;
bool cmd(pair<ll,ll>a,pair<ll,ll>b){
 
 return ((a.S>b.S)&&(a.F<b.F));
 
}
 
const int MAXN=1005;
 
int n,p[MAXN][MAXN];
 
double e[MAXN],skip[MAXN];
bool vis[MAXN];
 
int main(){
cin>>n;
	loop(i,n)
	loop(j,n)
		cin>>p[i][j];
 
	e[n-1]=0.0;
	
   loop(i,n-1)
		e[i]=1e9;
	
	loop(it,n-1){
		int u = -1;
		for(int i = 0; i < n; i++){
			if(vis[i])continue;
 
			if(u==-1)u = i;
			else if(e[i] < e[u])u = i;
		}
		vis[u]=true;
 
		loop(i,n)if(p[i][u]>0){
			if(vis[i])continue;
 
			if(e[i]>1e8){
				e[i]=e[u]+ 100.0/p[i][u];
				skip[i]=1.0-p[i][u]/100.0;
			}else{
				if(e[i] < e[u])continue;
 
				e[i]=(e[i]*(1.0-skip[i])+skip[i]*p[i][u]/100.0* e[u]) /(1.0-skip[i]*(1.0-p[i][u]/100.0));
				skip[i]=skip[i]*(1.0-p[i][u]/100.0);
			}
		}
	}
 
	cout<<fx<<setp(10)<<e[0];
 
	
}
