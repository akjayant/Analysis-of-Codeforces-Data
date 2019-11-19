#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ini(x, y) memset(x, y, sizeof(x))
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main() {
	fastio;
	int t;
	cin >> t;

	while (t--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;

		bool flg = 1;
		for (int x = 0; x <= k; ++x) {
			int y = k - x;
			if (x * c >= a && y * d >= b) {
				flg = 0;
				cout << x << ' ' << y << endl;
				break;
			}
		}

		if (flg) cout << -1 << endl;
	}

	return 0;
}