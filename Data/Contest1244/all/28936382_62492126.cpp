#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
#include<time.h>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<unordered_map>
#include<ctype.h>
#include<random>
#include<iostream>
using namespace std;
typedef long long ll;
typedef double db;
#define _Zero(a) memset(a,0,sizeof(a))
#define _Neg1(a) memset(a,-1,sizeof(a))
#define _Inf(a) memset(a,0x3f,sizeof(a))
#define _NegInf(a) memset(a,0xcf,sizeof(a))
#define _Rep(i,a,b) for(int (i)=(a);(i)<=(b);i++)
#define _Dep(i,a,b) for(int (i)=(a);(i)>=(b);i--)
#define _Out(a)	cerr<<#a<<" = "<<(a)<<endl
const int INF = 0x3f3f3f3f;
const int MAXN = 5e5 + 50;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const db EPS = 1e-6;
const db Pi = acos(-1);
void test() { cerr << "\n"; }
template <typename T,typename...Args>void test(T x,Args...args){cerr<<x<<" ";test(args...); }
ll qpow(ll a, ll b) {return b?((b&1)?a*qpow(a*a%MOD,b>>1)%MOD : qpow(a*a%MOD,b>>1))%MOD :1; }
ll qpow(ll a, ll b, ll c) {return b?((b&1)?a*qpow(a*a%c,b>>1)%c : qpow(a*a%c,b>>1)) % c: 1; }
ll gcd(ll a, ll b){return b?gcd(b,a% b): a; }
int sign(db x) { return x<-EPS ? -1: x>EPS; }
int dbcmp(db l, db r) { return sign(l - r); }

struct Edge
{
	int from, to, nxt;
}E[MAXN*2];
int head[MAXN], cntE;
void addE(int a, int b)
{
	E[cntE] = { a,b,head[a] };
	head[a] = cntE++;
}
int dfn[MAXN];
int du[MAXN];
int ans[6][MAXN];
ll c[3][MAXN];
int to[6][3] = { {1,2,0},{2,1,0},{0,2,1},{2,0,1},{0,1,2},{1,0,2} };
int cntN;
void dfs1(int u, int fa)
{
	dfn[++cntN] = u;
	for (int ei = head[u]; ei != -1; ei = E[ei].nxt)
	{
		if (E[ei].to == fa)continue;
		dfs1(E[ei].to, u);
	}
}
ll dfs2(int F, int u, int fa,int col, ll cos)
{
	int xx = to[F][(col+1)%3]; ans[F][u] = to[F][col%3];
	for (int ei = head[u]; ei != -1; ei = E[ei].nxt)
	{
		if (E[ei].to == fa)continue;
		return dfs2(F, E[ei].to,u,col+1,cos+c[to[F][(col+1) % 3]][E[ei].to]);
	}
	return cos;

}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		head[i] = -1;
		scanf("%lld", &c[0][i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &c[1][i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &c[2][i]);
	}
	for (int i = 1; i < n; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		addE(a, b); addE(b, a); du[a]++; du[b]++;
	}
	int s;
	for (int i = 1; i <= n; i++)
	{
		if (du[i] > 2)
		{
			printf("-1\n"); return 0;
		}
		if (du[i] == 1)s = i;
	}
	dfs1(s, -1);
	ll minv = LINF; int minpos = 0;

	for (int i = 0; i < 6; i++)
	{
		int x;
		if (i < 2)x = 0;
		else if (i < 4)x = 1;
		else x = 2;
		ll tmp=dfs2(i, s, -1, 2, c[to[i][2]][s]);
		if (tmp < minv)
		{
			minpos = i;
			minv = tmp;
		}
	}
	printf("%lld\n", minv);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", ans[minpos][i]+1);
	}



}
/*

*/