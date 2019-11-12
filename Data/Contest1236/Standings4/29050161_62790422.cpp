#include <bits/stdc++.h>
#define MOD (ll)(1e9 + 7)
#define MAX (ll)(1e6 + 4)
#define INF (ll)(1e9 + 1)
using namespace std;
using ll =  long long;
using ld = long double;

ll mult (ll a, ll b) {
	return (a * b) % MOD;
}

ll pw (ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) {
			res = mult (a, res);
		}
		b >>= 1;
		a = mult (a, a);
	}
	return res;
}

int main () {
	ll n, m;
	cin >> n >> m;
	cout << pw (((pw (2, m) - 1 + MOD) % MOD), n) << "\n";
}
