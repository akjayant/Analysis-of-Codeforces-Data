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
int n,ans=1,cnt,f[N];
char s[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	f[1]=1;f[2]=2;
	FOR(i,3,n) f[i]=(f[i-1]+f[i-2])%mod;
	FOR(i,1,n){
		if(s[i]=='m' || s[i]=='w') return puts("0"),0;
		if(s[i]!=s[i-1]){
			if(s[i-1]=='u' || s[i-1]=='n') ans=1ll*ans*f[cnt]%mod;
			cnt=0;
		}
		cnt++;
	}
	if(s[n]=='u' || s[n]=='n') ans=1ll*ans*f[cnt]%mod;
	printf("%d\n",ans);
}
