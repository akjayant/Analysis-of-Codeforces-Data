#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,a,b,c,d,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		a=(c+a-1)/c;b=(d+b-1)/d;
		if(a+b<=k) printf("%d %d\n",a,b);
		else printf("-1\n");
	}
	return 0;
}