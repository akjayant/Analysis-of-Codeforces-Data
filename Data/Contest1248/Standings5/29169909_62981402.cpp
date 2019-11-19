# include <bits/stdc++.h>
# define rr register
# define int long long
const int N=100010;
int a[N],b[N];
int cnta[2],cntb[2];
int T;
int n,m;
signed main(void){
	scanf("%I64d",&T);
	while(T--){
		memset(cnta,0,sizeof(cnta));
		memset(cntb,0,sizeof(cntb));
		scanf("%I64d",&n);
		for(rr int i=1;i<=n;++i){
			scanf("%I64d",&a[i]);
			++cnta[a[i]%2];
		}
		scanf("%I64d",&m);
		for(rr int i=1;i<=m;++i){
			scanf("%I64d",&b[i]);
			++cntb[b[i]%2];
		}
		printf("%I64d\n",cnta[0]*cntb[0]+cnta[1]*cntb[1]);
	}
	return 0;
}