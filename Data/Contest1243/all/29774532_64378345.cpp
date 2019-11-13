#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vii;
#define taskname ""
#define all(a) (a).begin(), (a).end()
#define pb push_back

const ll MOD = 1e9 + 7;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vi a(n);
		for (auto& x : a) {
			cin >> x;
		}
		sort(all(a));
		int l = 0, r = n + 1;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			auto it = lower_bound(all(a), m);
			if (n - (it - a.begin()) >= m) {
				l = m;
			}
			else {
				r = m;
			}
		}
		cout << l << "\n";
	}
	return 0;
}