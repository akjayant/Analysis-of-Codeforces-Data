#include "bits/stdc++.h"

using namespace std;

typedef long double db;
typedef long long ll;
typedef pair<db, db> pd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define mod 1000000007
#define maxn 100005

ll n, m, k, q, a[maxn], b[maxn];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		cin >> n;
		ll i1 = 0, i2 = 0, p1 = 0, p2 = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] % 2)
				i1++;
			else
				p1++;
		}
		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> b[i];
			if (b[i] % 2)
				i2++;
			else
				p2++;
		}

		ll ans = i1 * i2 + p1 * p2;
		cout << ans << endl;

	}

	return 0;
}
