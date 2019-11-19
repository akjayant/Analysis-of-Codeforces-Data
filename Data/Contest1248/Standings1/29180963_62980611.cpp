#include<bits/stdc++.h>
typedef long long lnt;
const lnt mod = 1e9 + 7;
lnt a[100100];
int main() {
	int n;
	scanf("%d",&n);
	for(int k=1;k<=n;k++) scanf("%lld",&a[k]);
	std::sort(a+1,a+n+1);
	lnt x=0,y=0;
	for(int k=1;k<=n;k++){
		if(k<=n/2) x+=a[k];
		else y+=a[k];
	}
	printf("%lld\n",x*x+y*y);
}