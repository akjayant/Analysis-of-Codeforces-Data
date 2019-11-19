#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int a,b,c,d,k,x,y; 
int main(){
	int T;scanf("%d",&T);
	for(;T;--T){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		x=a/c+(a%c>0);y=b/d+(b%d>0);
		if(x+y>k)puts("-1");
		else printf("%d %d\n",x,y);
	}
	return 0;
}
