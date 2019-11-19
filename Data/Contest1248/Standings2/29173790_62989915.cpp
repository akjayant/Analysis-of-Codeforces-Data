#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define LL long long 
#define LD long double
const LL mod=1e9+7;
int n,m;
LL f[100005],fff[100005],g[100005],ggg[100005];
int main()
{
	scanf("%d%d",&n,&m);
	fff[1]=2;f[1]=2;
	for(int i=2;i<=n;i++)
	{
		f[i]=(f[i-1]+fff[i-1])%mod;
		fff[i]=(fff[i-1]+fff[i-2])%mod;
	}
	//cout<<f[n]<<endl;
	ggg[1]=2;g[1]=f[n];
	for(int i=2;i<=m;i++)
	{
		g[i]=(g[i-1]+ggg[i-1])%mod;
		ggg[i]=(ggg[i-1]+ggg[i-2])%mod;
	}
	cout<<g[m]<<endl;
}