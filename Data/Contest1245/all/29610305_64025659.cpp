#include <bits/stdc++.h>
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define sz(s) (int)(s).size()
#define mkp make_pair
#define sqr(s) ((s) * (s))

using namespace std;

typedef complex<int> point;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

int n, x[2050], y[2050], c[2050], k[2050];

int p[2050], r[2050];
int find(int v) { 
	return (p[v] == v) ? v : (p[v] = find(p[v]));  
}

bool unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	if (r[a] < r[b])
		swap(a, b);
	p[b] = a;
	r[a] += r[b];
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	// freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i <= n; i++) {
		if (i)
			cin >> c[i];
		p[i] = i;
		r[i] = 1;
	}
	for (int i = 1; i <= n; i++)
		cin >> k[i];
	vector<pair<ll, pair<int, int>>> e;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			e.emplace_back(1LL * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), mkp(i, j));
		}
	}
	for (int i = 1; i <= n; i++) {
		e.emplace_back(c[i], mkp(0, i));
	}

	sort(ALL(e));
	ll ans = 0;
	vector<pair<int, int>> edg;
	vector<int> ver;
	for (int i = 0; i < sz(e); i++) {
		int u = e[i].second.first, v = e[i].second.second;
		if (unite(u, v)) {
			ans += e[i].first;
			if (u == 0)
				ver.push_back(v);
			else
				edg.push_back({u, v});
		}
	}
	cout << ans << endl;

	cout << sz(ver) << endl;
	for (auto v : ver)
		cout << v << " ";
	cout << endl << sz(edg) << endl;
	for (auto p : edg)
		cout << p.first << " " << p.second << endl;
}
