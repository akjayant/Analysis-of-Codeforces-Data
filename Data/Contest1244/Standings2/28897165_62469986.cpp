#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int ans=n;
		for(int i=1;i<=n;++i){
			int x;
			scanf("%1d",&x);
			if(x==1){
				ans=max(ans,max(i*2,(n-i+1)*2));
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
