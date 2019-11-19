#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=1e9+7;
int n,m;

ll f[maxn],g[maxn],h[maxn];

int main()
{
	f[0]=0;f[1]=2;f[2]=4;
	g[0]=0;g[1]=2;g[2]=2;
	h[0]=0;h[1]=2;h[2]=4;
	for(int i=3;i<maxn;i++){
		f[i]=(f[i-2]+f[i-1])%mod;
		g[i]=(g[i-1]+g[i-2])%mod;
		h[i]=(h[i-1]+g[i])%mod;
	}
	while(~scanf("%d %d",&n,&m)){
		ll ans=(f[n]+h[m-1])%mod;
		printf("%lld\n",ans);
	}
	return 0;
}