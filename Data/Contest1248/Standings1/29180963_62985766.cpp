#include<bits/stdc++.h>
typedef long long lnt;
const lnt mod = 1e9 + 7;
lnt f[100010];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	f[1]=2;f[2]=4;
	for(int k=3;k<=100000;k++){
		f[k]=(f[k-1]+f[k-2])%mod;
	}
	lnt ans=f[n]+f[m]-2;
	ans%=mod;
	if(ans<0) ans+=mod;
	printf("%lld\n",ans); 
}