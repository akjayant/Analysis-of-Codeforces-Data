#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll a[N];
ll k,ans,sum;
int n;
int main(){
	scanf("%d%lld",&n,&k);
	ll sum=0;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
	sort(a+1,a+n+1);
	ans=a[n]-a[1];
	for (int i=1;i<=n/2;i++) {
		ll s=k/(ll)i;
		if ((n&1)&&(i==n/2)) {
		if (s>=a[i+2]-a[i]) {
			ans=0;
		} else ans=a[i+2]-a[i]-s;
		}else
		if (!(n&1)&&(i==n/2)){
		if (s>=a[i+1]-a[i]) {
			ans=0;
		} else ans=a[i+1]-a[i]-s;
		} else {
		if (s<=(a[i+1]-a[i]+a[n-i+1]-a[n-i])) ans=min(ans,a[n-i+1]-a[i]-s); 
		}
		k-=1ll*i*(a[i+1]-a[i]+a[n-i+1]-a[n-i]);
		if (k<0) break;
	}  
	printf("%lld\n",ans);
}