#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+7, p = 1e9+7;
ll f[N][2];
ll qpow(ll x, ll k)
{
	ll res = 1;
	while(k)
	{
		if(k&1)
		{
			res = res*x%p;
		}
		k >>= 1;
		x = x*x%p;
	}
	return res;
}
int main()
{
	int n, m;
	ll ans = 0;
	scanf("%d%d", &n, &m);
	if(n>m)
	{
		swap(n, m);
	}
	f[1][0] = 2;
	for(int i = 2; i <= n; i++)
	{
		f[i][1] = f[i-1][0];
		f[i][0] = (f[i-1][0]+f[i-1][1])%p;
	}
	ans = (f[n][0]+f[n][1]-2)%p;
	memset(f, 0, sizeof(f));
	f[1][0] = 2;
	for(int i = 2; i <= m; i++)
	{
		f[i][1] = f[i-1][0];
		f[i][0] = (f[i-1][0]+f[i-1][1])%p;
	}
	printf("%lld\n", (ans+f[m][0]+f[m][1]+p)%p);
	return 0;
}
