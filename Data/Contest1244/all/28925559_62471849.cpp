#include<bits/stdc++.h>
using namespace std;
int t,tail,Q[1003],ans,n;
char S[1003];
int main() {
	scanf("%d",&t);
	for(int Case=1; Case<=t; ++Case) {
		scanf("%d",&n);
		scanf("%s",S);
		tail=0;
		for(int i=0; i^n; ++i)
			if(S[i]=='1') Q[++tail]=i+1;
//		ans=n+tail;
		ans=n;
		if(tail) {
			ans=max(ans,Q[tail]*2);
			ans=max(ans,(n-Q[1]+1)*2);
		} 
		printf("%d\n",ans);
	}
	return 0;
}
