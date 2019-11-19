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
	int n;
	cin >> n;
	map <int, int> m;
	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			m[i] += 1;
			n /= i;
		}
	}
	if (n != 1) {
		m[n] += 1;
	}
	if (m.size() == 1) {
		cout << m.begin()->first;
	}
	else {
		cout << 1;
	}
	return 0;
}