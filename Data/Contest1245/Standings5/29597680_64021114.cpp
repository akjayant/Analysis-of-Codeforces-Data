#include<cctype>
#include<cstdio>
#include<cstdlib>
#define rnt register int
using namespace std;
const int mod=1e9+7;
int f[100010]={1,1,2};
char s[100010];
inline int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
inline int mul(int x,int y){return 1ll*x*y%mod;}
int ans=1,la[2];
int main()
{
	for(rnt i=3;i<=1e5;i=-~i)
		f[i]=add(f[i-1],f[i-2]);
	scanf("%s",s);
	for(rnt i=0;s[i];i=-~i)
	{
		if(s[i]=='m'||s[i]=='w')
			return puts("0"),0;
		if(s[i]=='u')
		{
			ans=mul(ans,f[la[1]]);
			la[0]=-~la[0];la[1]=0;
			continue;
		}
		if(s[i]=='n')
		{
			ans=mul(ans,f[la[0]]);
			la[1]=-~la[1];la[0]=0;
			continue;
		}
		ans=mul(ans,mul(f[la[0]],f[la[1]]));
		la[0]=la[1]=0;
	}
	ans=mul(ans,mul(f[la[0]],f[la[1]]));
	printf("%d",ans);
	return 0;
}