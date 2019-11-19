#include<bits/stdc++.h>
#define M 100005
using namespace std;
int n,a[M];
long long k,sum[M];
int ans=1e9;
int check(int x,int y) {
	if(1ll*(x-1)*a[x]-(sum[x-1]-sum[0])+(sum[n]-sum[y])-1ll*(n-(y+1)+1)*a[y]<=k)return 1;
	return 0;
}
int main() {
	scanf("%d%lld",&n,&k);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)sum[i]=sum[i-1]+a[i];
	for(int i=1,j=0; i<=n; i++) {
		while(j<i&&check(j+1,i))j++;
		if(j>0&&check(j,i)) {
			long long t=k-(1ll*(j-1)*a[j]-(sum[j-1]-sum[0])+(sum[n]-sum[i])-1ll*(n-(i+1)+1)*a[i]);
			if(i==j)ans=0;
			else ans=min(1ll*ans,a[i]-a[j]-min(1ll*(a[j+1]-a[j]),t/j));
		}
	}
	for(int i=n,j=n+1;i>=1;i--){
		while(j>i&&check(i,j-1))j--;
		if(j<=n&&check(i,j)){
			long long t=k-(1ll*(i-1)*a[i]-(sum[i-1]-sum[0])+(sum[n]-sum[j])-1ll*(n-(j+1)+1)*a[j]);
			if(i==j)ans=0;
			else ans=min(1ll*ans,a[j]-a[i]-min(1ll*(a[j]-a[j-1]),t/(n-j+1)));
		}
	}
	printf("%d\n",ans);
	return 0;
}
