#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100000+10;
const ll P=1000000007;
ll f[MAXN];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	f[0]=1;f[1]=1;
	for(int i=2;i<=max(n,m);i++)
		f[i]=(f[i-1]+f[i-2])%P;
	ll ans=f[n]*2%P+2*f[m]%P-2;
	printf("%lld",ans%P);
	return 0;
}
