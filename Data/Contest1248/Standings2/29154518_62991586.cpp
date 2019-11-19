#include<cstdio>
const int MaxN=100000,mod=1000000007;
int n,m,f[MaxN+1];
inline int max(const int &a,const int &b)
{
	return a>b?a:b;
}
int main()
{
	int i;
	scanf("%d%d",&n,&m);
	f[1]=2,f[2]=4;
	for(i=3;i<=max(n,m);++i)
		f[i]=(f[i-1]+f[i-2])%mod;
	printf("%d\n",((f[n]-2+mod)%mod+f[m])%mod);
	return 0;
}