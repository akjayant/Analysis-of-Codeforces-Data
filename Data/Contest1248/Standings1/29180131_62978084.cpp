#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	for(;T--;){
		int n;
		scanf("%d",&n);
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(x&1)cnt1++;
			else cnt2++;
		}
		int m;
		long long ans=0;
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			int x;
			scanf("%d",&x);
			if(x&1)ans+=cnt1;
			else ans+=cnt2;
		}
		printf("%lld\n",ans);
	}
}