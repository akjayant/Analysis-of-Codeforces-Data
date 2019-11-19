# include <bits/stdc++.h>
# define int long long
# define rr register
const int N=100010,MOD=1e9+7;
int f[N][2][2];
signed main(void){
	int n,m;
	scanf("%I64d%I64d",&n,&m);
	f[1][1][0]=1;
	f[1][0][0]=1;
	for(rr int i=2;i<=std::max(n,m);++i){
		f[i][0][1]+=f[i-1][0][0];
		f[i][0][1]%=MOD;
		f[i][0][0]+=f[i-1][1][1]+f[i-1][1][0];
		f[i][0][0]%=MOD;
		f[i][1][1]+=f[i-1][1][0];
		f[i][1][1]%=MOD;
		f[i][1][0]+=f[i-1][0][1]+f[i-1][0][0];
		f[i][1][1]%=MOD;
	}
/*	for(rr int i=1;i<=n;++i){
		printf("%d %d %d %d\n",f[i][0][0],f[i][0][1],f[i][1][0],f[i][1][1]);
	}*/
	printf("%I64d",((f[n][0][0]+f[n][0][1]+f[n][1][0]+f[n][1][1])+(f[m][0][0]+f[m][0][1]+f[m][1][0]+f[m][1][1])-2)%MOD);
	return 0;
}