#include <bits/stdc++.h>
using namespace std;
int q,n;
int a[1050],b[1050];
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[a[i]]++;
		for(int i=n-1;i>=1;i--) b[i]+=b[i+1];
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,min(i,b[i]));
		printf("%d\n",ans);
	}
	return 0;
}