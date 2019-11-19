#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5+100;

int n, d[N];
ll c[3][N], did[N], soln[N];
vector<int> g[N];

int p[] = {0, 1, 2};
ll dfs(int u, int lev, int f = -1) {
	if(lev >= 3) lev -= 3;

	did[u] = p[lev];
	ll cur = c[p[lev]][u];
	for(int v : g[u]) if(v != f) {
		cur += dfs(v, lev + 1, u);
	} 
	return cur;
}

int main() {
	scanf("%d", &n);
	for(int i : {0, 1, 2})
		for(int j = 1; j <= n; j++)
			scanf("%lld", &c[i][j]);

	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
		d[u]++, d[v]++;
	}

	for(int i = 1; i <= n; i++) if(d[i] > 2) {
		puts("-1");
		return 0;
	}

	int cyc = 1;
	for(int i = 1; i <= n; i++) if(d[i] == 1) cyc = 0;
	if(cyc) {
		if(n % 3 != 0) {
			puts("-1");
			return 0;
		}

		int u = 1;
		int v = g[u].back();
		g[u].pop_back();
		g[v].erase(remove(g[v].begin(), g[v].end(), u), g[v].end());
	}

	for(int i = 1; i <= n; i++) if(d[i] == 1) {
		ll ans = LLONG_MAX;
		do{
			ll x = dfs(i, 0);
			if(x < ans) {
				for(int i = 1; i <= n; i++)
					soln[i] = did[i];
				ans = x;
			}
			ans = min(ans, x);
		} while(next_permutation(p, p + 3));
		printf("%lld\n", ans);
		for(int i = 1; i <= n; i++)
			printf("%d ", soln[i] + 1);
		return 0;
	}

	return 0;
}