#include<bits/stdc++.h>
using namespace std;
int t,n;
char c[1005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %s",&n,c+1);
		int ans=n;
		for(int i=1;i<=n;++i){
			if(c[i]=='1'){
				ans=max(ans,max(i,n-i+1)<<1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
