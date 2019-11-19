#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define reset(a, v) memset((a), v, sizeof(a))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N = 100005;

int n, m;
int P[N], Q[N];

int main() {
	int tc; cin >> tc;
	while (tc--) {
		cin >> n;
		int odd = 0, even = 0;
		for (int i = 0; i < n; i++) {
			cin >> P[i];
			if (P[i] & 1) odd++;
			else even++;
		}

		ll ans = 0;

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> Q[i];
			if (Q[i] & 1) ans += odd;
			else ans += even;
		}
		cout << ans << "\n";
	}
	return 0;
}