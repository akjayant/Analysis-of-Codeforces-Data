#include<bits/stdc++.h>
using namespace std;
char s[1005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d%s",&n,s+1);
		int mn=n+1,mx=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='1')mn=min(mn,i),mx=max(mx,i);
		printf("%d\n",max(n,max(mx,n-mn+1)<<1));
	}
	return 0;
}
