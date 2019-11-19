#include<bits/stdc++.h>
namespace csx_std {
	using namespace std;
	typedef long long ll;
	#define FOR(i,a,b) for (register ll i=(a);i<=(b);i++)
	#define For(i,a,b) for (register ll i=(a);i>=(b);i--)
	#define mem(i,j) memset(i,j,sizeof(i))
	#define pii pair<ll,ll>
	#define pb push_back
	#define MP make_pair
	#define fi first
	#define se second
	#define GO(u) for (register ll j=f[u];j!=-1;j=nxt[j])
	const ll N=1e5+5;
	const ll mod=1e9+7;
	inline ll qpow(ll x,ll y) {ll ret=1;for (;y;y>>=1,x=1LL*x*x%mod) if (y&1) ret=1LL*ret*x%mod;return ret;}
	inline ll Inv(ll x) {return qpow(x,mod-2);}
	inline void upd(ll &x,ll y) {x=(1LL*x+y)%mod;return;}
	inline ll chkmax(ll &x,ll y) {return (x<y)?(x=y,1):0;}
	inline ll chkmin(ll &x,ll y) {return (x>y)?(x=y,1):0;}
	inline ll read()
	{
		ll x=0,f=1;
		char c=getchar();
		while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
		while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0';c=getchar();}
		return f*x;
	}
	inline void write(ll x)
	{
		if (x<0) x=-x,putchar('-');
		if (x>9) write(x/10);
		putchar(x%10+'0');
		return;
	}
}
using namespace csx_std;
ll T,l,r,dp[101][2][2],ans1,ans2,ans3,ans;
ll bit1[101],bit2[101];
inline ll dfs(ll pos,ll lim1,ll lim2)
{
	if (!pos) return 1;
	if (dp[pos][lim1][lim2]!=-1) return dp[pos][lim1][lim2];
	ll tmp=0;
	tmp+=dfs(pos-1,lim1&&(bit1[pos]==0),lim2&&(bit2[pos]==0));
	if ((!lim1)||bit1[pos]) tmp+=dfs(pos-1,lim1,lim2&&(bit2[pos]==0));
	if ((!lim2)||bit2[pos]) tmp+=dfs(pos-1,lim1&&(bit1[pos]==0),lim2);
	dp[pos][lim1][lim2]=tmp;
	return tmp;
}
inline ll solve(ll m1,ll m2)
{
	if (m1<0||m2<0) return 0;
	mem(dp,-1);
	ll len1=0,len2=0;
	FOR(i,0,40) bit1[i]=bit2[i]=0;
	while (m1)
	{
		bit1[++len1]=m1%2;
		m1>>=1;
	}
	while (m2)
	{
		bit2[++len2]=m2%2;
		m2>>=1;
	}
	return dfs(max(len1,len2),1,1);
}
int main()
{
	T=read();
	while (T--)
	{
		l=read(),r=read();
		ans1=solve(r,r);
		ans2=solve(r,l-1);
		ans3=solve(l-1,l-1);
		ans=ans1-2*ans2+ans3;
		write(ans),putchar('\n');
	}
	return 0;
}
/*
3
1 4
323 323
1 1000000

1
2 2
*/