#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define PER(i,a,n) for(int i=n;i>=a;--i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<',';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head



#ifdef ONLINE_JUDGE
const int N = 5e6+50;
#else
const int N = 1e2+10;
#endif


//n个平面点, 可能有重复
//点i建站花费c_i
//连接点i,j每单位长度花费k_i+k_j
//两点距离为曼哈顿距离
//求最低价格

int n;

struct _ {
	int x,y,c,k;
} a[N];

int dis(int i, int j) {
	return abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
}

int cnt;
struct __ {
	int u,v;
	ll w;
} e[N];
short fa[N];
int Find(int x) {
	return fa[x]?fa[x]=Find(fa[x]):x;
}
vector<pii> edge;
bool used[N];

int main() {
	scanf("%d",&n);
	REP(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
	REP(i,1,n) scanf("%d",&a[i].c);
	REP(i,1,n) scanf("%d",&a[i].k);
	
	REP(i,1,n) e[++cnt]={n+1,i,(ll)a[i].c};
	REP(i,1,n) REP(j,1,n) {
		if (i!=j) e[++cnt]={i,j,(ll)dis(i,j)*(a[i].k+a[j].k)};
	}
	sort(e+1,e+1+cnt,[](__ a,__ b){return a.w<b.w;});
	ll ans = 0;
	REP(i,1,cnt) {
		int u=e[i].u,v=e[i].v;
		ll w = e[i].w;
		int uu=Find(u),vv=Find(v);
		if (uu==vv) continue;
		if (u!=n+1&&v!=n+1) edge.pb(pii(u,v));
		else used[u]=used[v]=1;
		if (uu==n+1) swap(uu,vv);
		fa[uu] = vv;
		ans += e[i].w;
	}
	printf("%lld\n",ans);
	vector<int> v;
	REP(i,1,n) if (used[i]) v.pb(i);
	printf("%d\n",(int)v.size());
	for (int i:v) printf("%d ",i);hr;
	printf("%d\n",(int)edge.size());
	for (auto t:edge) printf("%d %d\n",t.x,t.y);
}







