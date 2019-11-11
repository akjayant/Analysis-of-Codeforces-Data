#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char s[200005]; int n;
int add(int a,int b){a+=b; return a>=mod?a-mod:a;}
int f[200005];
int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	f[1]=1,f[2]=2;
	for(int i=3;i<=n;i++) f[i]=add(f[i-1],f[i-2]);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='m'||s[i]=='w')
		{
			puts("0");
			return 0;
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int cc=0;
		if(s[i]=='u')
		{
			while(s[i]=='u') cc++,i++;
			ans=1ll*ans*f[cc]%mod,i--;
		}
		else if(s[i]=='n')
		{
			while(s[i]=='n') cc++,i++;
			ans=1ll*ans*f[cc]%mod,i--;
		}
	}
	printf("%d\n",ans);
	return 0;
}