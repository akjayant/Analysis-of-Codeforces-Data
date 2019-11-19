#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main () {
	register int n; scanf("%d",&n);
	for(register int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1); register int mid=n/2+1;
	register long long ans=0,x=0,z=0;
	for(register int i=1;i<mid;++i) x+=a[i];
	for(register int i=mid;i<=n;++i) z+=a[i];
	ans=x*x+z*z; printf("%lld\n",ans);
	return 0;
}