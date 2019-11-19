#include<bits/stdc++.h>
#define M 1005
using namespace std;
char s[M];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		scanf("%s",s+1);
		int mn=1e9,mx=-1e9;
		for(int i=1; i<=n; i++){
			if(s[i]=='1'){
				mn=min(mn,i);
				mx=max(mx,i);
			}
		}
		if(mn!=1e9){
			printf("%d\n",max(n-mn+1,mx)*2);
		}
		else printf("%d\n",n);
	}
	return 0;
}
