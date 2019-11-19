#include<bits/stdc++.h>
using namespace std;
int p[100001],q[100001];
int main () {
	register int T; scanf("%d",&T);
	while(T--) {
		register int n; scanf("%d",&n);
		for(register int i=1;i<=n;++i) scanf("%d",&p[i]);
		register int m; scanf("%d",&m);
		for(register int i=1;i<=m;++i) scanf("%d",&q[i]);
		register long long x1=0,x2=0,z1=0,z2=0,ans=0;
		for(register int i=1;i<=n;++i) (p[i]%2!=0)?++x1:++x2;
		for(register int i=1;i<=m;++i) (q[i]%2!=0)?++z1:++z2;
		ans=(x1*z1)+(x2*z2); printf("%lld\n",ans);
	}
	return 0;
}