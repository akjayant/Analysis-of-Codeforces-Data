#include <bits/stdc++.h>

#define fi first
#define se second
#define m_p make_pair
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

typedef long long ll;

const int MAXN = 1123456;
const int MAXINT = 2147483098;
const ll MAXLL = 9223372036854775258LL;
const ll MOD = 1e9 + 7;

ll binpow (ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1LL)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		n >>= 1LL;
	}
	return res;
}

int main()
{
    fast_io;

    ll n, m;

    cin >> n >> m;
    ll pw = (binpow(2LL, m) - 1 + MOD)% MOD;
    cout << binpow(pw, n) << endl;

    return 0;
}
// i = 1 .. n
// res = (res * 2^m
