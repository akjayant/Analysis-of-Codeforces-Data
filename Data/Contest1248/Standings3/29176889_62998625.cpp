#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include <iostream>
#define LL long long
#define mod 1000000007LL
using namespace std;

LL f[100005][5];
LL jie[100005];

LL ksm(LL x, LL exp)
{
	LL ans=1;
	while (exp)
	{
		if (exp&1) ans=(ans*x)%mod;
		exp>>=1;
		x=(x*x)%mod;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n,m; cin>>n>>m;
	if (n<m) swap(n,m);
	jie[0]=1;
	for (int i=1; i<=m; i++) jie[i]=(jie[i-1]*i)%mod;
	f[2][0]=f[2][1]=f[2][3]=f[2][2]=1;
	f[1][0]=f[1][1]=1;
	for (int i=3; i<=n; i++)
	{
		f[i][0]+=f[i-1][2];
		f[i][0]%=mod;
		f[i][1]+=f[i-1][0]+f[i-1][2];
		f[i][1]%=mod;
		f[i][2]+=f[i-1][3]+f[i-1][1];
		f[i][2]%=mod;
		f[i][3]+=f[i-1][1];
		f[i][3]%=mod;
	}
	LL ans=0;
	ans=(f[n][0]+f[n][1]+f[n][2]+f[n][3]-2+mod)%mod;
//	cout<<ans<<endl;
	for (int i=0; i<=m/2; i++)
	{
		ans=(ans+2*(jie[m-i]*ksm(jie[i],mod-2)%mod*ksm(jie[m-i-i],mod-2)%mod)%mod)%mod;
//		cout<<ans<<endl;
	}
//	if (m==2) ans=(ans+2)%mod;
	cout<<ans<<endl;
	return 0;
}