#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long f[100001];
int main () {
	register int m,n; register long long ans;
	scanf("%d%d",&n,&m); f[1]=2,f[2]=4;
	for(register int i=3;i<=max(m,n);++i)
	    f[i]=(f[i-1]+f[i-2])%mod;
	ans=(f[m]+f[n]-f[1])%mod;
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}