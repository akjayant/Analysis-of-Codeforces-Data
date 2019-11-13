#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define go_precise cout << fixed << setprecision(15);
mt19937 rnd;

const ll mod = 1e9 + 7;
ll n,m;

ll binpow (ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a % mod;
	else {
		ll b = binpow (a, n/2);
		return b * b % mod;
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;
    ll ans = binpow(2, m) - 1;
    ans = binpow(ans, n);
    cout << (ans + mod) % mod << "\n";

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
