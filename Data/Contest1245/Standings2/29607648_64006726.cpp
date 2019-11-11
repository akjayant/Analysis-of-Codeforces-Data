#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int p=1e9+7;
long long f[maxn];
char s[maxn];
int n;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	f[0]=1;
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='m'||s[i]=='w'){flag=true;break;}
		f[i]=f[i-1];
		if(s[i]=='u'&&s[i-1]=='u')f[i]+=f[i-2];
		if(s[i]=='n'&&s[i-1]=='n')f[i]+=f[i-2];
		if(f[i]>=p)f[i]%=p;
	}
	if(flag)cout<<0;
	else cout<<f[n];
} 