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
		int n;
		string str;
		cin >> n >> str;

		int ans, s = -1, e = -1;
		for (int i = 0; i < sz(str); ++i) {
			if (s == -1 && str[i] == '1') s = i;
			if (str[i] == '1') e = i;
		}

		if (s == -1) ans = n;
		else if (s == e) ans = max({ n + 1, s + 1 << 1, n - s << 1 });
		else ans = 2 * max({ s + 1, n - s, n - e, e + 1 });

		cout << ans << endl;
	}

	return 0;
}