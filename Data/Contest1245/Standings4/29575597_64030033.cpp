/**
 * author:  apikdech
 * created: 01.11.2019 22:21:52
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e3 + 5;

ll x[N], y[N], c[N], k[N], ans = 0;
bool vis[N];
int p[N], sz[N];

int f(int v) {
	return (v == p[v] ? v : p[v] = f(p[v]));
}

bool unite(int u, int v) {
	u = f(u), v = f(v);
	if (u == v) return false;
	if (vis[u]) p[v] = u;
	else p[u] = v;
	return true;
}

ll dist(ll x1, ll y1, ll x2, ll y2) {
	ll dx = x1 - x2;
	ll dy = y1 - y2;
	return abs(dx) + abs(dy);
}

vector<pair<ll, pair<int, int>>> d;
vector<int> build;
vector<pair<int, int>> edge;
vector<pair<ll, int>> v;

void pre() {
	for (int i = 0; i < N; i++) p[i] = i, vis[i] = 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	pre();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		v.push_back({c[i], i});
		d.push_back({c[i], {i, i}});
	}
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll t = dist(x[i], y[i], x[j], y[j]) * (k[i] + k[j]);
			d.push_back({t, {i, j}});
		}
	}
	sort(d.begin(), d.end());
	sort(v.begin(), v.end());
	for (auto it : d) {
		if (it.second.first == it.second.second && !vis[f(it.second.first)]) {
			ans += it.first, vis[f(it.second.first)] = 1;
			build.push_back(it.second.first + 1);
		}
		if ((!vis[f(it.second.first)] || !vis[f(it.second.second)]) && unite(it.second.first, it.second.second)) {
			ans += it.first;
			edge.push_back({it.second.first + 1, it.second.second + 1});
		}
	}
	for (auto it : v) {
		if (!vis[f(it.second)]) {
			ans += it.first, vis[f(it.second)] = 1;
			build.push_back(it.second + 1);
		}
	}
	sort(build.begin(), build.end());
	cout << ans << "\n";
	cout << build.size() << "\n";
	for (int i = 0; i < (int)build.size(); i++) {
		cout << build[i] << " \n"[i + 1 == (int)build.size()];
	}
	cout << edge.size() << "\n";
	for (auto it : edge) {
		cout << it.first << " " << it.second << "\n";
	}
	return 0;
}
