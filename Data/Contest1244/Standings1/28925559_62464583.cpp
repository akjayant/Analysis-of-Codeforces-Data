#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d,e,x,y;
int main() {
	scanf("%d",&t);
	for(int Case=1;Case<=t;++Case){
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		x=(a-1)/c+1,y=(b-1)/d+1;
		if(x+y>e)puts("-1");
		else printf("%d %d\n",e-y,y);
	}
	return 0;
}
