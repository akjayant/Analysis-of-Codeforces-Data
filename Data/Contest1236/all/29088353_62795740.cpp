#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm> 
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll Qpow(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b&1)
			ans = (ans*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return ans;
}

int main()
{
	ll n, m; 
	scanf("%lld%lld", &n, &m);
	ll ans = Qpow(Qpow(2, m)-1, n);
	cout << ans;
	return 0;	
}











