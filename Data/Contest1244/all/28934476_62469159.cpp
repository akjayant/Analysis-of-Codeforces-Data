#include<bits/stdc++.h>
using namespace std;
int n;
char A[1005];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		scanf("%s",A+1);
		int l=1e9,r=1;
		for(int i=1;i<=n;i++){
			if(A[i]=='1'){
				l=min(l,i);
				r=max(r,i);
			}
		}
		if(l>r)printf("%d\n",n);
		else {
			int ans=n;
			ans=max(ans,2*l);
			ans=max(ans,2*(n-l+1));
			ans=max(ans,2*r);
			ans=max(ans,2*(n-r+1));
			ans=max(ans,l+r-l+1);
			printf("%d\n",ans);
		}
	}
	return 0;
}