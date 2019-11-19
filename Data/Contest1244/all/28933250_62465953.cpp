#include<bits/stdc++.h>
using namespace std;
int T,a,b,c,d,k,ansa,ansb;
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		ansa=(a+c-1)/c,ansb=(b+d-1)/d;
		if(ansa+ansb>k)printf("-1\n");
		else printf("%d %d\n",ansa,ansb);
	}
	return 0;
}