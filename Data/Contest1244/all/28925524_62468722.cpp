#include<bits/stdc++.h>
using namespace std;
int T,n;
char s[1005];
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%s",&n,s+1);
		int ans=n;
		for(int i=1; i<=n; i++)
			if(s[i]=='1') 
				ans=max(ans,max(i,n-i+1)+max(i,n-i+1));
		printf("%d\n",ans);
	}
	return 0;
}