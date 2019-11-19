#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
const int mod=1e9+7;
ll a[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	a[1]=0;
	a[2]=1;
	for(int i=3;i<=1e5;i++)
	{
		a[i]=(a[i-1]+a[i-2]+1)%mod;
	}
	ll ans=2*(1+a[n]+a[m])%mod;
	printf("%lld\n",ans);
	return 0;
}