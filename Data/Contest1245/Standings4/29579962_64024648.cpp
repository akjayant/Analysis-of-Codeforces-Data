#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, ii> lii;

const int N = 2003;

int k[N], par[N];
ii a[N];
lii ed[N * N + N];
int e = 0, n;
vector<int> ss;
vector<ii> cc;

int findSet(int x) {
	if (par[x] < 0) return x;
	return par[x] = findSet(par[x]);
}

bool join(int x, int y) {
	if ((x = findSet(x)) == (y = findSet(y))) return false;
	if (par[x] > par[y]) swap(x, y);
	par[x] += par[y];
	par[y] = x;
	return true;
}

int main() {
	memset(par, -1, sizeof(par));
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].X >> a[i].Y;
	}
	for (int i = 1; i <= n; ++i) {
		int c; cin >> c; ed[e++] = make_pair(1LL * c, make_pair(0, i));
	}
	for (int i = 1; i <= n; ++i) cin >> k[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ed[e++] = make_pair(1LL * (k[i] + k[j]) * (1LL * (abs(a[i].X - a[j].X) + abs(a[i].Y - a[j].Y))), make_pair(i, j));
		}
	}
	sort(ed, ed + e);
	long long ans = 0;
	for (int i = 0; i < e; ++i) {
		if (join(ed[i].Y.X, ed[i].Y.Y)) {
			ans += ed[i].X;
			if (ed[i].Y.X == 0) {
				ss.push_back(ed[i].Y.Y);
			} else {
				cc.push_back(make_pair(ed[i].Y.X, ed[i].Y.Y));
			}
		}
	}
	cout << ans << '\n';
	cout << ss.size() << '\n';
	for (int x : ss) cout << x << ' ';
	cout << '\n';
	cout << cc.size() << '\n';
	for (ii x : cc) {
		cout << x.X << ' ' << x.Y << '\n';
	}

	return 0;
}
