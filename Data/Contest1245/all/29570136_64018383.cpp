#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 100002
typedef long long ll;
char s[N];
int n;
int a[N][2],cnt;
ll f[N];
ll p=1e9+7;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='w'||s[i]=='m')
		{
			puts("0");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='u')
		{
			int j=i;
			while(j<=n&&s[j]=='u')j++;
			j--;
			a[++cnt][0]=j-i+1;
			a[cnt][1]=1;
			i=j;
		}
		else if(s[i]=='n')
		{
			int j=i;
			while(j<=n&&s[j]=='n')j++;
			j--;
			a[++cnt][0]=j-i+1;
			a[cnt][1]=2;
			i=j;
		}
	}
	f[1]=1;f[2]=2;
	for(int i=3;i<=n;i++)f[i]=(f[i-1]+f[i-2])%p;
	ll ans=1;
	for(int i=1;i<=cnt;i++)
	{
		ans=(ans*f[a[i][0]])%p;
	}
	printf("%I64d\n",ans);
}

