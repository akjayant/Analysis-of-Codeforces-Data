#include<bits/stdc++.h>
#define ll long long
#define M 100005
using namespace std;
int n,a[M];
ll K,sum[M];
int main() {
//	freopen("data.in","r",stdin);
	scanf("%d%I64d",&n,&K);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)sum[i]=sum[i-1]+a[i];
//	int ans=a[n]-a[1];
//	for(int i=1; i<=n; i++) {
//		int l=a[i],r=a[n];
//		ll now=1ll*i*a[i]-sum[i];
//		while(l<=r) {
//			int mid=(l+r)>>1,k=lower_bound(a+1,a+n+1,mid)-a;
//			ll p=(sum[n]-sum[k-1])-1ll*(n-k+1)*mid;
//			if(p+now<=K)ans=min(ans,mid-a[i]),r=mid-1;
//			else l=mid+1;
//		}
//	}
	int l=1,r=n;
	bool ok=1;
	while(l<r&&K&&ok) {
		if(l>=(n-r+1)) {
			ll k=K/(n-r+1);
			if(k==0)ok=0;
			if(k>=a[r]-a[r-1]) {
				K-=1ll*(a[r]-a[r-1])*(n-r+1);
				r--;
			} else {
				K-=1ll*k*(n-r+1);
				a[r]-=k;
			}
		} else {
			ll k=K/l;
			if(k==0)ok=0;
			if(k>=a[l+1]-a[l]) {
				K-=1ll*(a[l+1]-a[l])*l;
				l++;
			} else {
				K-=1ll*k*l;
				a[l]+=k;
			}
		}
	}
	printf("%d\n",a[r]-a[l]);
	return 0;
}