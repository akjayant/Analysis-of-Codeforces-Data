#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rint register int
using namespace std;
typedef long long ll;
const int N=100000+10,mod=1e9+7;
int n,m;
ll f[N];
int main()
{
	scanf("%d%d",&n,&m);
	if(n>m)
		swap(n,m);
	f[1]=f[2]=1;
	for(rint i=3;i<=m+1;++i)
		f[i]=(f[i-1]+f[i-2])%mod;
	ll ans=f[m+1];
	for(rint i=1;i<n;++i)
		ans=(ans+f[i])%mod;
	printf("%lld",2*ans%mod);
	return 0;
}

