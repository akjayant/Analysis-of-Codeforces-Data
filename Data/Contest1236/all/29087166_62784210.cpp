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
		int a, b, c;
		cin >> a >> b >> c;

		int ans = 0;
		while (c >= 2 && b >= 1) ans += 3, b--, c -= 2;
		while (b >= 2 && a >= 1) ans += 3, a--, b -= 2;

		cout << ans << endl;
	}

	return 0;
}