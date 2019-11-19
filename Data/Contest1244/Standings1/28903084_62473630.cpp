#include"bits/stdc++.h"

using namespace std;
char s[1010];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		int f=0,g=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				f=i;
				break;
			}
		}
		for(int i=n;i>=1;i--){
			if(s[i]=='1'){
				g=i;
				break;
			}
		}
		if(!f){
			printf("%d\n",n);
			continue;
		}
		f--;
		g=n-g;
		printf("%d\n",max(n,max(2*n-2*f,2*n-2*g)));
	}
	return 0;
}
                             