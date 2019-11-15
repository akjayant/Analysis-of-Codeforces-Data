#include<bits/stdc++.h>

using namespace std;
const int N=110000;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long LL;
const LL mod=1e9+7;
char s[N];
LL f[N];
int n;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	f[0]=1;
	int flag=0;
	for (int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if (s[i]=='m'||s[i]=='w') flag=1;
		if (i>=1&&(s[i]=='u'&&s[i-1]=='u'||s[i]=='n'&&s[i-1]=='n')) f[i]=(f[i]+f[i-2])%mod;
	}
	if (flag) cout<<0<<endl;
	else cout<<f[n]<<endl;
	return 0;
}