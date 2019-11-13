#include <cstdio>
#include <cstring>
char s[200001];int f[100001],n;const int p=1e9+7;
int main()
{
	scanf("%s",s+1);int n=strlen(s+1);f[0]=1;f[1]=1;f[2]=2;for(int i=3;i<=n;++i)f[i]=(f[i-1]+f[i-2])%p;long long ans=1;int cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='m'||s[i]=='w'){printf("0\n");return 0;}
		if(s[i]!=s[i-1]||s[i]!='n'&&s[i]!='u')
		{
			ans*=f[cnt+1];cnt=0;ans%=p;
		}
		else ++cnt;
	}
	ans*=f[cnt+1];ans%=p;printf("%lld\n",ans);return 0;
}