#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c,d,K;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&K);
		int x=a%c==0?a/c:a/c+1;
		int y=b%d==0?b/d:b/d+1;
		if(x+y<=K)printf("%d %d\n",x,y);
		else puts("-1");
	}
	return 0;
}
