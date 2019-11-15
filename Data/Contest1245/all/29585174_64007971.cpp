#include<cstdio>
const int N=1e5;
const int mod=1e9+7;
char s[N+10];
int f[N+10],sum,ans=1;
int main()
{
	f[0]=f[1]=1;
	for(int i=2;i<=N;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	scanf("%s",s);
	for(int i=0;s[i];)
		if(s[i]=='m'||s[i]=='w')
		{
			puts("0");
			return 0;
		}
		else if(s[i]=='u'||s[i]=='n')
		{
			sum=1;
			i++;
			while(s[i]==s[i-1])sum++,i++;
			ans=ans*1ll*f[sum]%mod;
		}
		else i++;
	printf("%d",ans);
	return 0;
}
