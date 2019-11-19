// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9,maxn=2e5+5;

int n,k;
int a[maxn],sum[maxn],suf[maxn];


int check(int d){
	int res=1e18;
	for(int i=1;i<=n;i++){
		int curp = lower_bound(a+1,a+n+1,a[i]+d)-a;
		res = min(res,a[i]*(i-1)-sum[i-1]+suf[curp]-(a[i]+d)*(n-curp+1));
	}
	for(int i=n;i>=1;i--){
		int curp = lower_bound(a+1,a+n+1,a[i]-d)-a;
		res = min(res,suf[i+1]-a[i]*(n-i)+(a[i]-d)*(curp-1)-sum[curp-1]);
	}
	return k>=res;
}

signed main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)suf[i] = suf[i+1]+a[i];
	for(int i=1;i<=n;i++)sum[i] = sum[i-1]+a[i]; 
	int ans=a[n]-a[1];
	int l=0,r=ans;
	
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);

	return 0;
}
