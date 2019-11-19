#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int t,n,m,p[maxn],q[maxn];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int cnta1=0,cnta2=0,cntb1=0,cntb2=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
			if(p[i]%2==0) cnta1++;
			else cnta2++;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&q[i]);
			if(q[i]%2==0) cntb1++;
			else cntb2++;
		}
		ll ans=1ll*cnta1*cntb1+1ll*cnta2*cntb2;
		printf("%lld\n",ans);
	}
	return 0;
} 