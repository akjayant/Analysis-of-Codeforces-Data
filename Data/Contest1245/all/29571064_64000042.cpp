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
int T,a,b,c,n,vis[N],cnt;
char ans[N],s[N];
int main()
{
	T=read();
	while (T--)
	{
		cnt=0;
		n=read(),a=read(),b=read(),c=read();
		FOR(i,1,n) vis[i]=0;
		scanf("%s",s+1);
		FOR(i,1,n)
		{
			switch (s[i])
			{
				case 'R':
					if (b) b--,cnt++,ans[i]='P',vis[i]=1;
					break;
				case 'P':
					if (c) c--,cnt++,ans[i]='S',vis[i]=1;
					break;
				case 'S':
					if (a) a--,cnt++,ans[i]='R',vis[i]=1;
					break;
			}
		}
		FOR(i,1,n) if (!vis[i])
		{
			if (a) a--,ans[i]='R';
			else if (b) b--,ans[i]='P';
			else if (c) c--,ans[i]='S';
		}
		if (cnt>=(n+1)/2)
		{
			printf("YES\n");
			FOR(i,1,n) putchar(ans[i]);
			putchar('\n');
		}
		else printf("NO\n");
	}
	return 0;
}
