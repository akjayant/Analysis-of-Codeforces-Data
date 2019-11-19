#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		int now=(a+c-1)/c+(b+d-1)/d;
		if(now<=e)printf("%d %d\n",(a+c-1)/c,(b+d-1)/d);
		else puts("-1");
	}
	return 0;
}