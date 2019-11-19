#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
const int maxn=1e6+200;
typedef long long ll;
ll a[maxn];

void init()
{
	a[1]=1;a[2]=2;
	for(int i=3;i<=(int)1e5+2;i++) a[i]=a[i-1]+a[i-2],a[i]%=mod;
}

int main()
{
	init();
	int n,m;scanf("%d%d",&n,&m);
	ll ans=(a[n]+a[m]-1)%mod;
	ans*=2;
	ans%=mod;
	printf("%lld\n",ans);
}