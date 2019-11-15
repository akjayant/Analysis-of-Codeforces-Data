#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x3fffffff
using namespace std;
#include<cstdio>
#include<cmath>
 #include<bits/stdc++.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x3fffffff
const int mod=1e9+7;
using namespace std;
int n;
char s[100005];
long long f[100005];
int main()
{
	int t,a,b,c,x,y,z;
	long long ans=1;
	scanf("%s",s+1);
	f[0]=1;
	f[1]=1;
	f[2]=2;
	f[3]=3;
	n=strlen(s+1);
	for (int i=4;i<=n;i++) f[i]=(2*f[i-2]+f[i-3])%mod;
	int ff=1,tot=1;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='m' || s[i]=='w') ff=0;
		if (s[i]==s[i+1]) tot++;
		else
		{
			if (s[i]=='u' || s[i]=='n') ans=(ans*f[tot])%mod;
			tot=1;
		}
	}
	if (ff==0) puts("0");
	else printf("%lld\n",ans);
}
