#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5,mod=1e9+7;
int n,m;
long long ans,f[maxn][2];
int main(){
	f[1][0]=2;f[1][1]=0;
	for(int i=2;i<=100000;i++){
		f[i][0]=f[i-1][0]+f[i-1][1];
		f[i][0]%=mod;
		f[i][1]=f[i-1][0];
	}
	scanf("%d%d",&n,&m);
	ans=((f[n][0]+f[n][1]-1)+(f[m][0]+f[m][1]-1))%mod;
	printf("%lld\n",ans);
	return 0;
}