#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define mod 1000000007
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll fastexp(ll a, ll b)
{
	ll ans = 1;
	a %= mod;
	while (b > 0)
	{
		if (b & 1)
			ans = (ans * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	ll x = fastexp(2ll, m);
	x = (x - 1) % mod;
	cout << fastexp(x, n) << '\n';
	return 0;
}