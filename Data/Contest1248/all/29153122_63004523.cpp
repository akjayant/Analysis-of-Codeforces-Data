#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,m,a[100010],b[100010];
signed main() {
	scanf("%I64d%I64d",&n,&m);
	if (n>m) swap(n,m);
	a[1]=2;a[2]=4;
	for (int i=3; i<=n; i++) a[i]=(a[i-1]+a[i-2])%mod;
	b[1]=a[n];b[2]=(b[1]+2)%mod;
	for (int i=3; i<=m; i++) b[i]=((b[i-1]+b[i-2]-b[1]+2)%mod+mod)%mod;
	printf("%I64d\n",b[m]);
	return 0;
}