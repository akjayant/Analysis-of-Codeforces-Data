#include<cstdio>
#include<cmath>
int main(){
	int ts;
	scanf("%d",&ts);
	while(ts--){
		int a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		a=ceil(a*1.0/c),b=ceil(b*1.0/d);
		if(a+b<=k) printf("%d %d\n",a,b);
		else printf("-1\n");
	}
	return 0;
}