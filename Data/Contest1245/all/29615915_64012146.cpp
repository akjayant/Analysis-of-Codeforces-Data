#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#define MAXN 100005
using namespace std;
const int MOD=1e9+7;
typedef long long ll;
int fib[MAXN];
char s[MAXN];
int main()
{
	fib[1]=1;
	for (int i=2;i<MAXN;i++) fib[i]=(fib[i-1]+fib[i-2])%MOD;
	scanf("%s",s+1);
	int n=strlen(s+1);
	char las=0;
	int cnt=0,ans=1;
	for (int i=1;i<=n+1;i++)
	{
		if (s[i]=='m'||s[i]=='w')
		{
			puts("0");
			return 0;
		}
		if (s[i]==s[i-1]) ++cnt;
		else
		{
			if (las=='n'||las=='u') ans=(ll)ans*fib[cnt+1]%MOD;
			las=s[i];cnt=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
