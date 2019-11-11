#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
ll f[100088];
int n;
char s[100005];
int main()
{
	f[0]=f[1]=1;
	for(int i=2;i<=1e5+5;i++)f[i]=(f[i-1]+f[i-2])%mod;
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)if(s[i]=='w'||s[i]=='m')return !printf("0\n");
	vector<int>v;
	ll ans=1;
	for(int i=0;i<n;)
		if(s[i]=='u'||s[i]=='n')
		{
			int st=i;
			while(i<n&&s[i]==s[st])++i;
			if(i-st<=1)continue;
			ans=ans*f[i-st]%mod;
		}
		else
			++i;
	printf("%lld\n",ans);
	return 0;
}