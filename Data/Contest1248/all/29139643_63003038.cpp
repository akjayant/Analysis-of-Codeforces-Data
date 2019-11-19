#include<bits/stdc++.h>
#define  ll long long
using namespace std;

const int maxn=1e5+10;
const int mod=1e9+7;

ll poww( ll a,ll b )
{
	ll ans=1;
	while( b )
	{
		if( b&1 ) ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}
ll a[maxn],b[maxn],c[maxn];

void init()
{
	a[1]=2,a[2]=4;
	c[1]=0,c[2]=2;
	b[1]=0,b[2]=2;
	for( int i=3;i<=1e5;i++ )
	{
		a[i]=(a[i-1]+a[i-2])%mod;
		b[i]=(b[i-1]+b[i-2])%mod;
		c[i]=(c[i-1]+b[i])%mod;
	}
}

int main()
{
	int n,m;
	ll ans=1;
	cin>>n>>m;
	init();
	ans=(a[n]+c[m])%mod;
	cout<<ans<<endl;
}