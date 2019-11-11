#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1e9+7;
int x,y,n,r1,p1,s1,r2,p2,s2,t;
char s[100011];
int b[100011];
long long f[100011];
int main()
{
	scanf("%s",s);
	for (int i=0;i<strlen(s);i++)
	if (s[i]=='m'||s[i]=='w') 
	{
		printf("0");
		return 0;
	}
	long long ans=1;
	f[1]=1; f[2]=2;
	for (int i=3;i<=100000;i++) f[i]=(f[i-1]+f[i-2])%mod;
	for (int i=0;i<strlen(s);i++)
	if (!b[i]&&s[i]=='u'&&i<strlen(s)-1)
	{
		b[i]=1;
		int tot=1,p=i;
		while (s[p+1]=='u') 
		{
			p++; tot++;
			b[p]=1;
		}
		ans=(ans*f[tot])%mod; 
	}
	for (int i=0;i<strlen(s);i++)
	if (!b[i]&&s[i]=='n'&&i<strlen(s)-1)
	{
		b[i]=1;
		int tot=1,p=i;
		while (s[p+1]=='n') 
		{
			p++; tot++;
			b[p]=1;
		}
		ans=(ans*f[tot])%mod; 
	}
	printf("%I64d",ans);
} 