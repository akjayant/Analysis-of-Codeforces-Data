#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100008;
const ll mod = 1e9 + 7;

int n, m, num;

ll fibonacciIteratively(ll n)
{
	ll result = 0;
	ll nextItem = 1;
	for (ll i = 1; i <= n; ++i)
	{
		ll tmp = nextItem;
		nextItem += result;
		result = tmp;
		result %= mod;
	}

	return result%mod;
}
int main()
{
	scanf("%d %d", &n,&m);
	ll ans;
	ans = fibonacciIteratively(m+1) * 2 + fibonacciIteratively(n+1) * 2 - 2;
	printf("%lld", ans%mod);
}