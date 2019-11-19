#include<bits/stdc++.h>
int T,odd,even,n,m;
typedef long long LL;
int main(){
	//scanf
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		odd=even=0;
		LL ans=0;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if (x%2)++odd;
			else ++even;
		}
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if (x%2)ans+=1LL*odd;
			else ans+=1LL*even;
		}
		printf("%lld\n",ans);
	}
	return 0;
}