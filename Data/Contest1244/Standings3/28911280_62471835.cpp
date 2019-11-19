#include<bits/stdc++.h>
using namespace std;
int n;
char c[1005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",c+1);
		int ans=n;
		for(int i=1;i<=n;i++){
			if(c[i]=='1')ans=max(ans,2*max(i,n-i+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}