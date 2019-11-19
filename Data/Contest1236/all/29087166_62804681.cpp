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
const int MOD = 1e9 + 7;

int main() {
	fastio;
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> obx[100000], oby[100000];
	for (int a, b, i = 0; i < k; ++i) {
		cin >> a >> b;
		obx[--a].push_back(--b);
		oby[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) sort(all(obx[i]));
	for (int i = 0; i < m; ++i) sort(all(oby[i]));

	int x = 0, y = 0, dir = 1;
	int ux = -1, bx = n, ly = -1, ry = m;
	ll cnt = 1, prv = 0;

	while (1) {
		if (dir == 1) {
			int p = upper_bound(all(obx[x]), y) - obx[x].begin();
			if (p == sz(obx[x])) {
				cnt += ry - y;
				y = ry - 1;
			}
			else {
				int t = min(obx[x][p], ry);
				cnt += t - y;
				y = t - 1;
			}
			ux = x;
		}
		else if (dir == 2) {
			int p = upper_bound(all(oby[y]), x) - oby[y].begin();
			if (p == sz(oby[y])) {
				cnt += bx - x;
				x = bx - 1;
			}
			else {
				int t = min(oby[y][p], bx);
				cnt += t - x;
				x = t - 1;
			}
			ry = y;
		}
		else if (dir == 3) {
			int p = lower_bound(all(obx[x]), y) - obx[x].begin();
			if (p == 0) {
				cnt += y - ly;
				y = ly + 1;
			}
			else {
				int t = max(obx[x][--p], ly);
				cnt += y - t;
				y = t + 1;
			}
			bx = x;
		}
		else {
			int p = lower_bound(all(oby[y]), x) - oby[y].begin();
			if (p == 0) {
				cnt += x - ux;
				x = ux + 1;
			}
			else {
				int t = max(oby[y][--p], ux);
				cnt += x - t;
				x = t + 1;
			}
			ly = y;
		}

		--cnt;
		if (prv == cnt) break;

		prv = cnt;
		if (++dir == 5) dir = 1;
	}

	if (cnt + k != (ll)n * m) cout << "No";
	else cout << "Yes";

	return 0;
}