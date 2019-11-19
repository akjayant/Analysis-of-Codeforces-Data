# include <bits/stdc++.h>
# define rr register
# define int long long
const int N=100010;
int a[N];
int n;
signed main(void){
	scanf("%I64d",&n);
	for(rr int i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
	}
	std::sort(a+1,a+1+n);
	int cnta=0,cntb=0;
	for(rr int i=1;i<=n/2;++i){
		cnta+=a[i];
	}
	for(rr int i=n/2+1;i<=n;++i){
		cntb+=a[i];
	}
	printf("%I64d",cnta*cnta+cntb*cntb);
	return 0;
}