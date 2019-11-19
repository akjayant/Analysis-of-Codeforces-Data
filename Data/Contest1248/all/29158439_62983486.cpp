#include<bits/stdc++.h>
using namespace std;
int t,n,m,p,cnt[2][2];
long long ans;
int main(){
	scanf("%d",&t);
	while(t--){
		ans=0;
		cnt[0][0]=cnt[0][1]=cnt[1][0]=cnt[1][1]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&p);
			cnt[0][abs(p)%2]++;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&p);
			cnt[1][abs(p)%2]++;
		}
		ans=1ll*cnt[0][0]*cnt[1][0]+1ll*cnt[0][1]*cnt[1][1];
		printf("%lld\n",ans);
	}
	return 0;
}