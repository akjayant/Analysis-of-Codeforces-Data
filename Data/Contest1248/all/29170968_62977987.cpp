#include<stdio.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
int T,n,t;
long long x[2],y[2];
int main(){
	scanf("%d",&T);
	while (T--){
		x[0]=x[1]=y[0]=y[1]=0;
		scanf("%d",&n);
		while (n--){
			scanf("%d",&t);
			x[t&1]++;
		}
		scanf("%d",&n);
		while (n--){
			scanf("%d",&t);
			y[t&1]++;
		}	
		printf("%I64d\n",x[0]*y[0]+x[1]*y[1]);
	}
	return 0;
}