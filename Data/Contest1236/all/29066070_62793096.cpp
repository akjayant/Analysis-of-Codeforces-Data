#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define mod 1000000007
#define maxn 100005

ll n, m;

ll power(ll a, ll k)
{
	ll res = 1;
	while (k)
	{
		if (k & 1)
			res = res * a % mod;
		a = a * a % mod;
		k /= 2;
	}
	return res;
}

int main()
{
	//freopen("monotonic.in", "r", stdin);
	//freopen("monotonic.out", "w", stdout);
	cin >> n >> m;
	cout << power((power(2, m) - 1 + mod) % mod, n) % mod << endl;
	return 0;
}