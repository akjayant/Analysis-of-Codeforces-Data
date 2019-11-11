#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
char st[100005];
ll n,m,f[100005],cnt,ans;
int main()
{
	scanf("%s",st+1);
	n=strlen(st+1);
	f[1]=1;
	f[0]=1;
	ans=1;
	for(int i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=1;i<=n;i++)
	 {
	 	if(st[i]=='m'||st[i]=='w'){cout<<0<<endl;exit(0);}
	 	if((st[i]=='u'||st[i]=='n')&&(st[i]==st[i-1])){cnt++;continue;}
	 	ans=ans*f[cnt]%mod;
	 	cnt=1;
	 }
	ans=ans*f[cnt]%mod;
	cout<<ans<<endl;
}