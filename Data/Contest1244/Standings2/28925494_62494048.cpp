#include<bits/stdc++.h>
#define N 100005
#define LL long long
#define Ms(a,b) memset(a,b,sizeof a)
#define db(x) cerr<<#x<<"="<<x<<endl;
#define db2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define db3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
using namespace std;
int n,a[N];
LL k,sum[N];
LL calc(int l,int r) {
	return 1ll*l*a[l]-sum[l]+sum[n]-sum[r-1]-1ll*(n-r+1)*a[r];
}
int main() {
	scanf("%d%lld",&n,&k);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++)sum[i]=sum[i-1]+a[i];
	int ans=a[n]-a[1];
	a[n+1]=2e9;
	for(int l=1,r=1; l<=n; l++) {
		r=max(r,l);
		while(r<=n&&calc(l,r)>k)r++;
		if(r<=n) {
			if(l==r)ans=0;
			else {
				ans=min(1ll*ans,a[r]-a[l]-min(1ll*a[l+1]-a[l],(k-calc(l,r))/l));
				ans=min(1ll*ans,a[r]-a[l]-min(1ll*a[r]-a[r-1],(k-calc(l,r))/(n-r+1)));
			}
		}
	}
	for(int l=n,r=n; r>=1; r--) {
		l=min(r,l);
		while(l>=1&&calc(l,r)>k)l--;
		if(l>=1) {
			if(l==r)ans=0;
			else {
				ans=min(1ll*ans,a[r]-a[l]-min(1ll*a[l+1]-a[l],(k-calc(l,r))/l));
				ans=min(1ll*ans,a[r]-a[l]-min(1ll*a[r]-a[r-1],(k-calc(l,r))/(n-r+1)));
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
