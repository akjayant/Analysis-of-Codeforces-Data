#include <bits/stdc++.h>
using namespace std;

const int md = (int) 1e9 + 7;

struct DSU {
	vector<int> lab;
	DSU(int n) {	
		lab.assign(n, -1);
	}
	int root(int u) {
		return (lab[u] < 0 ? u : lab[u] = root(lab[u]));
	}
	void merge(int u, int v) {
		u = root(u);
		v = root(v);
		if (u != v) {
			if (lab[u] > lab[v]) {
				swap(u, v);
			}
			lab[u] += lab[v];
			lab[v] = u;
		}
	}
};

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> pos(n);
	vector<int> c(n);
	vector<int> k(n);
	for (int i = 0; i < n; ++i) {
		cin >> pos[i].first >> pos[i].second;
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> k[i];
	}
	vector<vector<long long>> e;
	for (int i = 0; i < n; ++i) {
		e.push_back(vector<long long>({c[i], i, 1}));
	} 
	auto get = [&](int x, int y) {
		return 1LL * (k[x] + k[y]) * (1LL * abs(pos[x].first - pos[y].first) + abs(pos[x].second - pos[y].second));
	};
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			e.push_back(vector<long long>({get(i, j), i, j, 2}));
		}
	}
	int m = (int) e.size();
	vector<int> index(m);
	for (int i = 0; i < m; ++i) {
		index[i] = i;
	}
	sort(index.begin(), index.end(), [&](int i, int j) {
		return (*e[i].begin()) < (*e[j].begin());
	});
	vector<bool> good(n, false);
	DSU dsu(n);
	long long cost = 0;
	vector<int> listv;
	vector<pair<int, int>> liste;
	for (int i = 0; i < m; ++i) {
		int id = index[i];
		//cerr << e[id][0] << " " << e[id].back() << "\n";
		if (e[id].back() == 1) {
			auto u = dsu.root(e[id][1]);
			if (!good[u]) {
				good[u] = true;
				listv.push_back(e[id][1]);
				cost += e[id][0];	
			}
		} else {
			auto u = dsu.root(e[id][1]);
			auto v = dsu.root(e[id][2]);
			if (good[u] && good[v]) {
				continue;
			}
			if (u == v) {
				continue;
			}
			if (u != v) {
				bool tmp = good[u] | good[v];
				dsu.merge(u, v);
				good[u] = good[v] = tmp;
				liste.push_back({e[id][1], e[id][2]});
				cost += e[id][0];
			}
		}
	}
	cout << cost << "\n";
	cout << listv.size() << "\n";
	for (auto i: listv) {
		cout << i + 1 << " ";
	}
	cout << "\n";
	cout << liste.size() << "\n";
	for (auto i: liste) {
		cout << i.first + 1 << " " << i.second + 1 << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}