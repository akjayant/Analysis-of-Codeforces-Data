#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#define fo(i,l,r) for (auto i=l,_end=r;i<=_end;++i)
#define fd(i,l,r) for (auto i=l,_end=r;i>=_end;--i)
#define FI(x) freopen(x,"r",stdin)
#define FO(x) freopen(x,"w",stdout)
using ll=long long;
using namespace std;

const ll mod=1000000007;
const int N=1e5+10;

int n;
char a[N];
ll f[N];

int main() {
	f[0]=f[1]=1;
	fo(i,2,N-1) f[i]=(f[i-1]+f[i-2])%mod;
	scanf("%s",a);
	n=strlen(a);
	ll ans=1;
	fo(i,0,n-1) {
		if (a[i]=='w'||a[i]=='m') ans=0;
		if (a[i]!='u'&&a[i]!='n') continue;
		int cnt=0;
		fo(j,i,n-1) {
			if (a[j]==a[i]) cnt++;
			else break;
		}
		ans=ans*f[cnt]%mod;
		i+=cnt-1;
	}
	printf("%lld\n",ans);
}


