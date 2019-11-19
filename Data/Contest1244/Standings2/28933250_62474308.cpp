#include<bits/stdc++.h>
using namespace std;
#define M 2005
int t,n,i,ans,cnt;
char s[M];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d%s",&n,s+1),ans=n,cnt=0;
		for(i=1; i<=n; i++)if(s[i]=='1')ans=max(ans,max(i*2,(n-i+1)*2)),cnt++;
		if(cnt>=2)ans=max(ans,n+2);
		printf("%d\n",ans);
	}
	return 0;
}