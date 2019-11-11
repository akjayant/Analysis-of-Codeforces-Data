#include <cstdio>
#include <cstring>
const int S=100003,mod=1000000007;
int n,f[S];
char a[S];
int main()
{
	scanf("%s",a+1);
	n=strlen(a+1);
	f[0]=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]=='m' || a[i]=='w')
		{
			puts("0");
			return 0;
		}
		f[i]=f[i-1];
		if (a[i]==a[i-1] && a[i]=='n')
			f[i]=(f[i]+f[i-2])%mod;
		if (a[i]==a[i-1] && a[i]=='u')
			f[i]=(f[i]+f[i-2])%mod;
	}
	printf("%d\n",f[n]);
	return 0;
}