#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long a[1000010];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);	
	if(n>m) swap(n,m);
	a[0]=2,a[1]=2,a[2]=4;
	for(int i=3;i<=m;i++) a[i]=(a[i-1]+a[i-2])%mod;
	long long ans=a[m];
	for(int i=0;i<=n-2;i++) ans=(ans+a[i])%mod;
	printf("%lld",ans);
	return 0;
}