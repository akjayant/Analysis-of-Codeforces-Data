#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;

int n,m,p[maxn],q[maxn];

ll odd1,odd2,even1,even2;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		odd1=odd2=even1=even2=0;
	
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
			if(p[i]&1)odd1++;
			else even1++;
		}
		
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&q[i]);
			if(q[i]&1)odd2++;
			else even2++;
		}
	
		ll ans=odd1*odd2 + even1*even2;
		printf("%lld\n",ans);
	}
	return 0;
}