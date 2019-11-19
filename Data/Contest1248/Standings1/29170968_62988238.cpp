#include<stdio.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
int f[110000],n,m;
const int p=1e9+7;
long long ans;
int main(){
	f[1]=1;f[2]=2;
	scanf("%d%d",&n,&m);
	fo(i,3,100000) f[i]=(f[i-1]+f[i-2])%p;
	ans=(f[n]+f[m]-1)%p;
	ans=ans*2%p;
	ans=(ans+p)%p;
	printf("%I64d\n",ans);
	return 0;
}