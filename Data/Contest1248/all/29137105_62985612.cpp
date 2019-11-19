#include "bits/stdc++.h"

using namespace std;

typedef long double db;
typedef long long ll;
typedef pair<db, db> pd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define mod 1000000007
#define maxn 100005

ll n, m, k, q, a[maxn];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	ll s = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s += a[i];
	}

	sort(a, a + n);

	ll s1 = 0, s2 = 0;
	for (int i = n - 1, j = 0; i >= j; i--, j++) {
		s1 += a[i];
		if (i > j)
			s2 += a[j];
	}

	cout << s1 * s1 + s2 * s2;

	return 0;
}
