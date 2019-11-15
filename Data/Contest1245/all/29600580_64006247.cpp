#include<cstdio> 
#include<cstring>
#include<algorithm>
#define mod 1000000007
using namespace std;

int n,i,j;
char str[200005];
long long f[200005];

int main()
{
//	freopen("read.in","r",stdin);
	scanf("%s",str+1);
	while (str[n+1]!=0) n++;
	f[0]=1;
	for (i=1;i<=n;i++)
	{
		if ((str[i]=='w')||(str[i]=='m')) break;
		if (str[i]=='n')
		{
			if (str[i-1]=='n') f[i]=(f[i-2]+f[i-1])%mod;
			else f[i]=(f[i-1])%mod;
			continue;
		}
		if (str[i]=='u')
		{
			if (str[i-1]=='u') f[i]=(f[i-2]+f[i-1])%mod;
			else f[i]=(f[i-1])%mod;
			continue;
		}
		f[i]=f[i-1];
	}
	printf("%lld",f[n]);
}