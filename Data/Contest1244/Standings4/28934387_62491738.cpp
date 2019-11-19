#include <bits/stdc++.h>
typedef long long ll;
const int N = 1000005;
ll n,k,a[N],b[N],cc;

void init(){
	for (int i=1;i<=n;++i) a[i]=0,b[i]=0;
}

int main() {
	scanf("%lld%lld", &n, &k);
	init();
	ll pt=k;
	if (n*(n+1)/2>k){puts("-1");return 0;}
	for (int i=1;i<=n;i++) a[i]=i,b[i]=i;
	k-=n*(n+1)/2;
	for (int i=1;i<=n/2;i++){
		if ((n-2*i+1)>k){
			int ret=i+k;
			std::swap(a[i],a[ret]);
			printf("%lld\n", pt);
			for (int j=1;j<=n;j++) printf("%lld ",a[j]);
			puts("");
			for (int j=1;j<=n;j++) printf("%lld ",b[j]);
			return 0;
		}
		if ((n-2*i+1)==k){
			int ret=i+k;
			std::swap(a[i],a[ret]);
			printf("%lld\n", pt);
			for (int j=1;j<=n;j++) printf("%lld ",a[j]);
			puts("");
			for (int j=1;j<=n;j++) printf("%lld ",b[j]);
			return 0;
		}
		std::swap(a[i],a[n-i+1]);
		k-=(n-2*i+1);
	}
	printf("%lld\n", pt-k);
	for (int i=1;i<=n;i++) printf("%d ",i);
	puts("");
	for (int i=n;i>=1;i--) printf("%d ",i);
	return 0;
}