#include<bits/stdc++.h>
using namespace std;
int T;
int main() {
	scanf("%d",&T);
	while(T--) {
		int a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int x=(a/c)+((a%c)!=0),y=(b/d)+((b%d)!=0);
		if(x+y>k)printf("-1\n");
		else printf("%d %d\n",x,y);
	}
	return 0;
}