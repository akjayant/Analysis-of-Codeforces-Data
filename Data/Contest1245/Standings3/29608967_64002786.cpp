#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

char s[100005];
int mo=1000000007;
int a[100005];
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	a[0]=a[1]=1;
	for(int i=2;i<=100000;i++) a[i]=(a[i-1]+a[i-2])%mo;
	int cntu=0,cntn=0,ans=1;
	len++;s[len]='a';
	for(int i=1;i<=len;i++)
	{
		if(s[i]=='u')
			cntu++;
		if(s[i]=='n')
			cntn++;
		if(s[i]!='u') ans=1LL*ans*a[cntu]%mo,cntu=0;
		if(s[i]!='n') ans=1LL*ans*a[cntn]%mo,cntn=0;
		if(s[i]=='m'||s[i]=='w') return !printf("0");
	}
	printf("%d\n",ans);
}
