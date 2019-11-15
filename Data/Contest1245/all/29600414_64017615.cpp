#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int t;
char s[1000005];
ll f[1000005],ans=1,p=1e9+7;
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	f[1]=1;f[2]=2;
	for(int i=3;i<=len;i++){f[i]=f[i-1]+f[i-2];f[i]%=p;}
	for(int i=0;i<len;i++)
	{
		int now=1;
		if(s[i]=='n'||s[i]=='u')
		while(s[i+1]==s[i]&&i<len-1){i++;now++;}
		
		ans*=f[now];ans%=p;
		if(s[i]=='m'||s[i]=='w'){ans=0;break;}
	}
	printf("%lld",ans);
	
	
	return 0;
}