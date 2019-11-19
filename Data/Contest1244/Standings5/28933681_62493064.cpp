#include<bits/stdc++.h>
#include<chrono>
#include<random>
#define int long long
#define double long double
#define INF 1e18
#define pii pair<int,int>
#define endl "\n"
#define all(mas) mas.begin(),mas.end()
#define forn(i,n) for(int i = 0; i < n; i++)
#define forn_(i,n) for(int i = n - 1; i >= 0; i--)
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, root = 0, res = INF;
vector<int> c[3], g[100002], col;

int dfs(int v,int p) {
	int cost = c[col[v]][v];

	for (auto i : g[v]) {
		if (p == i) continue;		
		if (col[i] == -1) {
			vector<int> temp(3,0);
			temp[col[p]] = 1;
			temp[col[v]] = 1;

			forn(j, 3)
				if (temp[j] == 0)
					col[i] = j;
		}

		cost += dfs(i, v);
	}

	return cost;
}

int get_cost(vector<int> perm) {
	col.clear();
	col.assign(n,-1);

	col[root] = perm[0];

	forn(i, g[root].size())
		col[g[root][i]] = perm[i + 1];

	return dfs(root, -1);
}

void fail() {
	cout << -1;
	exit(0);
}

signed main() {
#ifdef LOCAL_DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif		
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	col.resize(n);

	forn(i, 3) {
		c[i].resize(n);

		forn(j, n)
			cin >> c[i][j];
	}

	forn(i, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(auto i : g)
		if (i.size() > 2)
			fail();

	vector<int> perm = { 0,1,2 },best;

	do {
		int temp = get_cost(perm);

		if (temp < res) {
			res = temp;
			best = perm;
		}
	} while (next_permutation(all(perm)));

	cout << res << endl;

	get_cost(best);

	for (auto i : col)
		cout << i + 1 << ' ';

	return 0;
}