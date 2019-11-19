#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=100000;
const int MOD=1e9+7;
int n,m;
int a[N];
signed main()
{
	cin>>n>>m;
	a[0]=2;
	a[1]=2;
	for(int i=2;i<=max(n,m);i++) a[i]=(a[i-1]+a[i-2])%MOD;
	int ans=a[n];
	for(int i=0;i<=m-2;i++) ans=(ans+a[i])%MOD;
	printf("%lld\n",ans);
	return 0;
}
