#include<bits/stdc++.h>
using namespace std;
#define M 100005
int n,i,a[M],l,r,ans,b;
long long k;
int main() {
	scanf("%d%I64d",&n,&k);
	for(i=1; i<=n; i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1),l=1,r=n;
	while(l<r) {
		while(l<r&&a[l+1]==a[l])l++;
		while(r>l&&a[r-1]==a[r])r--;
		if(l==r)break;
		if(l<n-r+1) {
			if(1ll*l*(a[l+1]-a[l])<=k)k-=1ll*l*(a[l+1]-a[l]),l++;
			else {
				b=k/l,a[l]+=b;
				break;
			}
		} else {
			if(1ll*(n-r+1)*(a[r]-a[r-1])<=k)k-=1ll*(n-r+1)*(a[r]-a[r-1]),r--;
			else {
				b=k/(n-r+1),a[r]-=b;
				break;
			}
		}
	}
	printf("%d\n",a[r]-a[l]);
	return 0;
}