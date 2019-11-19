#include<bits/stdc++.h>
#define N 1010
using namespace std;
char s[N];
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans=n;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				ans=max(ans,2*i);
				ans=max(ans,2*(n-i+1));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}