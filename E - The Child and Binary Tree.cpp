/*                                        problim link:http://codeforces.com/contest/438/submission/38206725
                                          Author:Ahmed_Abd_Al_Mowla*/
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef complex<double> base;
#define loop(i,n) for(int i=0;i<n;i++)
#define reb(n)   for(int i=0;i<n;i++)
template <class T>inline void arin(T* st, T* nd){while(st<nd)cin>>*st++;}
 
const int MAXN = 131072*2 + 5;
const double PI = acos(-1);
const ll MOD = 998244353;
 
 
int rev[MAXN];
base wlen_pw[20][MAXN];
 
 
ll power(ll b,ll p,ll MOD)
{
    ll ret = 1;
    while(p)
    {
        if(p&1)
            ret = ret * b % MOD;
        b = b * b % MOD;
        p >>= 1;
    }
    return ret;
}
 
void fft (base a[], int n, bool invert) {
	for (int i=0; i<n; ++i)
		if (i < rev[i])
			swap (a[i], a[rev[i]]);
 
    int LG = 1;
	for (int len=2; len<=n; len<<=1,LG++) {
		double ang = 2*PI/len * (invert?-1:+1);
		int len2 = len>>1;
 
 
		for (int i=0; i<n; i+=len) {
			base t,
				*pu = a+i,
				*pv = a+i+len2,
				*pu_end = a+i+len2,
				*pw = wlen_pw[LG];
			for (; pu!=pu_end; ++pu, ++pv, ++pw) {
				t = *pv * *pw;
				*pv = *pu - t;
				*pu += t;
			}
		}
	}
 
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}
 
void calc_rev (int n, int log_n) {
	for (int i=0; i<n; ++i) {
		rev[i] = 0;
		for (int j=0; j<log_n; ++j)
			if (i & (1<<j))
				rev[i] |= 1<<(log_n-1-j);
	}
}
 
inline ll roundLongLong(base x)
{
    return (ll)roundl(x.real());
}
 
inline void print(const vector<ll> &cc)
{
    for(int i=0;i<cc.size();i++)
        cout<<(cc[i] > MOD / 2 && true? cc[i] - MOD: cc[i])<<" \n"[i+1==cc.size()];
}
 
inline void print(vector<base> &cc)
{
    for(int i=0;i<cc.size();i++)
        cout<<fixed<<cc[i]<<" \n"[i+1==cc.size()];
}
 
void pre(int n,bool invert)
{
    int LG = 1;
    for (int len=2; len<=n; len<<=1, LG++) {
		double ang = 2*PI/len * (invert?-1:+1);
        int len2 = len>>1;
		base wlen (cosl(ang), sinl(ang));
		wlen_pw[LG][0] = base (1, 0);
		for (int i=1; i<len2; ++i)
			wlen_pw[LG][i] = {cos(ang*i),sin(ang*i)};
    }
}
 
vector<ll> multiply(const vector<ll> &A,const vector<ll> &B)
{
    vector<base> A1(A.size()), A2(A.size());
    for(int i=0;i<A.size();i++)
        A1[i] = {A[i] & (0xffff),0}, A2[i] = {A[i] >> 16,0};
    vector<base> B1(B.size()), B2(B.size());
    for(int i=0;i<B.size();i++)
        B1[i] = {B[i] & (0xffff),0}, B2[i] = {B[i] >> 16,0};
    int n = 1;
    int log_n = 0;
    while(n < max(A.size(), B.size()))
        n <<= 1, log_n++;
    n <<= 1, log_n++;
    A1.resize(n), A2.resize(n), B1.resize(n), B2.resize(n);
    calc_rev(n,log_n);
    pre(n,false);
    fft(A1.data(),n,false), fft(A2.data(),n,false), fft(B1.data(),n,false), fft(B2.data(),n,false);
    vector<base> X(n),Y(n),Z(n);
    for(int i=0;i<n;i++)
        X[i] = A1[i] * B1[i], Z[i] = A2[i] * B2[i], Y[i] = (A1[i] + A2[i]) * (B1[i] + B2[i]);
    pre(n,true);
    fft(X.data(),n,true), fft(Y.data(),n,true), fft(Z.data(),n,true);
    for(int i=0;i<Y.size();i++)
        Y[i] -= X[i] + Z[i];
    vector<ll> ret(n);
    ll two_16 = (1<<16) % MOD;
    ll two_32 = (1ll<<32) % MOD;
    for(int i=0;i<ret.size();i++)
        ret[i] = ((roundLongLong(X[i]) + roundLongLong(Y[i]) % MOD * two_16 + roundLongLong(Z[i]) % MOD * two_32) % MOD + MOD) % MOD;
    return ret;
}
 
 
vector<ll> inverse_Generating_Function(vector<ll> A, int n)
{
    int n2 = 1;
    while(n2 < n)
        n2 <<= 1;
    n = n2;
    A.resize(n);
 
    n2 = 1;
    vector<ll> prev;
    ll inv = power(A[0],MOD-2,MOD); // 1/A[0] % MOD
    prev.push_back(inv);
    while(n2 < n)
    {
        n2 <<= 1;
        vector<ll> F (n2);
        for(int i=0;i<n2;i++)
            F[i] = A[i];
        vector<ll> temp = multiply(multiply(prev,prev),F);
        prev.resize(n2);
        for(int i=0;i<n2;i++)
            prev[i] = (2*prev[i] - temp[i] + MOD) % MOD;
    }
    return prev;
}
 
 
 
vector<ll> SquareRoot_Generating_Function(vector<ll> A, int n)
{
    int n2 = 1;
    while(n2 < n)
        n2 <<= 1;
    n = n2;
    A.resize(n);
    const ll inv2 = power(2,MOD-2,MOD);
    n2 = 1;
    vector<ll> prev;
    prev.push_back(1);
    while(n2 < n)
    {
        n2 <<= 1;
        vector<ll> F (n2);
        for(int i=0;i<n2;i++)
            F[i] = A[i];
        vector<ll> temp = multiply(F,inverse_Generating_Function(prev,n2));
        temp.resize(n2);
        prev.resize(n2);
        for(int i=0;i<n2;i++)
            prev[i] = (prev[i] + temp[i]) * inv2 % MOD;
    }
    return prev;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<ll> A(100001);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        A[x]++;
    }
    for(int i=0;i<A.size();i++)
        A[i] = (A[i] * -4 % MOD + MOD) % MOD;
    A[0] = 1;
    A = SquareRoot_Generating_Function(A,m+1);
    A[0] = (A[0] + 1) % MOD;
    A = inverse_Generating_Function(A,m+1);
    A.resize(m+1);
    for(int i=0;i<m+1;i++)
        A[i] = 2*A[i]%MOD;
    for(int i=1;i<=m;i++)
        cout<<A[i]<<endl;
 
    return 0;
}
