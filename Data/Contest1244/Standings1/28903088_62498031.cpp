#include<bits/stdc++.h>
#define ll long long
#define M 100006
using namespace std;
int A[M],B[M],cnt[M];
int main(){
	int n;
	ll k;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),B[i]=A[i];
	sort(B+1,B+n+1);
	int len=unique(B+1,B+n+1)-B-1;
	for(int i=1;i<=n;i++)A[i]=lower_bound(B+1,B+len+1,A[i])-B,cnt[A[i]]++;
	int l=1,r=len,ans=1e9;
	while(l<r&&k>0){
		if(cnt[r]<=cnt[l]){
			ll now=1ll*(B[r]-B[r-1])*cnt[r];
			if(k<=now){
				ll u=k/cnt[r];
				ans=B[r]-u-B[l];
				break;
			}
			k-=now;
			cnt[r-1]+=cnt[r];
			r--;
		}
		else {
			ll now=1ll*(B[l+1]-B[l])*cnt[l];
			if(k<=now){
				ll u=k/cnt[l];
				ans=B[r]-u-B[l];
				break;
			}
			k-=now;
			cnt[l+1]+=cnt[l];
			l++;
		}
	}
	if(l==r)ans=0;
	printf("%d\n",ans);
	return 0;
}