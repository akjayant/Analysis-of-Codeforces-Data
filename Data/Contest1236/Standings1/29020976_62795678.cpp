#include<bits/stdc++.h>
#define FOR(i,a,b) for (register ll i=(a);i<=(b);i++)
#define For(i,a,b) for (register ll i=(a);i>=(b);i--)
#define mem(i,j) memset(i,j,sizeof(i))
#define GO(u) for (register ll j=f[u];j!=-1;j=nxt[j])
#define fi first
#define se second
#define pb push_back
#define pii pair<ll,ll>
#define MP make_pair
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll n,m,ans;
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
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
inline ll qpow(ll x,ll y)
{
	ll ret=1;
	while (y)
	{
		if (y&1) ret=1LL*ret*x%mod;
		y>>=1;
		x=1LL*x*x%mod;
	}
	return ret;
}
int main()
{
	n=read(),m=read();
	m=qpow(2,m)-1;
	m=(1LL*m+mod)%mod;
	ans=qpow(m,n);
	write(ans);
	return 0;
}
