#include<bits/stdc++.h>
namespace csx_std {
	using namespace std;
	typedef long long ll;
	#define FOR(i,a,b) for (register int i=(a);i<=(b);i++)
	#define For(i,a,b) for (register int i=(a);i>=(b);i--)
	#define mem(i,j) memset(i,j,sizeof(i))
	#define pii pair<int,int>
	#define MP make_pair
	#define fi first
	#define se second
	#define GO(u) for (register int j=f[u];j!=-1;j=nxt[j])
	const int N=1e5+5;
	const int mod=1e9+7;
	inline int qpow(int x,int y) {int ret=1;for (;y;y>>=1,x=1LL*x*x%mod) if (y&1) ret=1LL*ret*x%mod;return ret;}
	inline int Inv(int x) {return qpow(x,mod-2);}
	inline void upd(int &x,int y) {x=(1LL*x+y)%mod;return;}
	inline int chkmax(int &x,int y) {return (x<y)?(x=y,1):0;}
	inline int chkmin(int &x,int y) {return (x>y)?(x=y,1):0;}
	inline int read()
	{
		int x=0,f=1;
		char c=getchar();
		while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
		while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0';c=getchar();}
		return f*x;
	}
	inline void write(int x)
	{
		if (x<0) x=-x,putchar('-');
		if (x>9) write(x/10);
		putchar(x%10+'0');
		return;
	}
}
using namespace csx_std;
struct edge{
	int u,v;
	ll w;
	bool operator<(const edge &e)const{return w<e.w;}
}e[N*25],ans[N];
int n,x[N],y[N],c[N],k[N],el,fa[N],al,cnt1,cnt2;
ll sum;
int dis(int i,int j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int main()
{
	n=read();
	FOR(i,1,n) x[i]=read(),y[i]=read();
	FOR(i,1,n) c[i]=read();
	FOR(i,1,n) k[i]=read();
	FOR(i,1,n) e[++el]=(edge){i,n+1,c[i]};
	FOR(i,1,n) FOR(j,i+1,n) e[++el]=(edge){i,j,1ll*(k[i]+k[j])*dis(i,j)};
	FOR(i,1,n+1) fa[i]=i;
	sort(e+1,e+el+1);
	FOR(i,1,el){
		int u=e[i].u,v=e[i].v;
		ll w=e[i].w;
		if(getfa(u)==getfa(v)) continue;
		fa[getfa(u)]=getfa(v);
		sum+=w;
		ans[++al]=e[i];
		if(v==n+1) cnt1++;
		else cnt2++;
	}
	printf("%lld\n%d\n",sum,cnt1);
	FOR(i,1,al) if(ans[i].v==n+1) printf("%d ",ans[i].u);
	puts("");
	printf("%d\n",cnt2);
	FOR(i,1,al) if(ans[i].v!=n+1) printf("%d %d\n",ans[i].u,ans[i].v);
	return 0;
}
