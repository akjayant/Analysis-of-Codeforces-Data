#include <bits/stdc++.h>
using namespace std;

constexpr int kN = 2019;

int par[kN], dfs_par[kN], c[kN], k[kN], sel[kN];
pair<int, int> p[kN], rem[kN];
vector<int> g[kN];

int Find(int x) {
	return x == par[x] ? x : par[x] = Find(par[x]);
}

int64_t Cost(int i, int j) {
	return 1LL * (k[i] + k[j]) * (abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second));
}

pair<pair<int, int>, tuple<int64_t, int, int>> Dfs(int x, int pr) {
	dfs_par[x] = pr;
	tuple<int64_t, int, int> ans = {INT64_MAX, -1, -1};
	pair<int, int> vtx = {c[x], x};
	for (int y : g[x]) {
		if (y == pr) continue;
		auto res = Dfs(y, x);
		vtx = min(vtx, res.first);
		ans = min({ans, res.second, make_tuple(-Cost(x, y) + res.first.first, res.first.second, y)});
	}
	return {vtx, ans};
}

int main() {
	cin.tie(nullptr), ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < n; i++) cin >> k[i];
	for (int i = 0; i < n; i++) par[i] = i;
	vector<tuple<int64_t, int, int>> edges;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			edges.emplace_back(Cost(i, j), i, j);
		}
	}
	sort(edges.begin(), edges.end());
	int cc = n;
	int64_t tree_cost = 0;
	for (auto t : edges) {
		if (cc == 1) break;
		int pi = Find(get<1>(t)), pj = Find(get<2>(t));
		if (pi != pj) {
			par[pi] = pj;
			--cc;
			g[get<1>(t)].push_back(get<2>(t));
			g[get<2>(t)].push_back(get<1>(t));
			tree_cost += Cost(get<1>(t), get<2>(t));
		}
	}
	pair<int, int> root = {c[0], 0};
	for (int i = 0; i < n; i++) root = min(root, {c[i], i});
	vector<int> roots;
	roots.push_back(sel[1] = root.second);
	int64_t cur_ans = tree_cost + root.first;
	pair<int64_t, int> ans = {cur_ans, 1};
	for (int i = 2; i <= n; i++) {
		tuple<int64_t, int, int> res = {INT64_MAX, -1, -1};
		for (int r : roots) {
			res = min(res, Dfs(r, r).second);
		}
		roots.push_back(get<1>(res));
		sel[i] = get<1>(res);
		int xx = get<2>(res), yy = dfs_par[xx];
		g[xx].erase(find(g[xx].begin(), g[xx].end(), yy));
		g[yy].erase(find(g[yy].begin(), g[yy].end(), xx));
		cur_ans += get<0>(res);
		ans = min(ans, {cur_ans, i});
		rem[i] = {xx, yy};
	}
	cout << ans.first << '\n' << ans.second << '\n';
	for (int i = 1; i <= ans.second; i++) cout << sel[i] + 1 << ' ';
	cout << '\n' << n - ans.second << '\n';
	for (int i = n; i > ans.second; i--) {
		cout << rem[i].first + 1 << ' ' << rem[i].second + 1 << '\n';
	}
}
