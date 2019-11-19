//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 17;

int n, m, ans, mn[MAXN];
vector<int> adj[MAXN];
set<int> s;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int v, u;
		cin >> v >> u;
		adj[v].pb(u);
		adj[u].pb(v);
	}

	for (int i = 1; i <= n; i++)
		s.insert(i), sort(adj[i].begin(), adj[i].end());
	int l = 1, r = 1;
	while (!s.empty()) {
		mn[r] = *s.begin();
		r++;
		s.erase(s.begin());
		while (l < r) {
			vector<int> v;
			int u = mn[l];
			l++;
			int siz = adj[u].size();
			int where = 0;
			for (auto i : s) {
				while (where != siz && adj[u][where] < i)
					where++;
				if (where == siz || adj[u][where] != i)
					v.pb(i);
			}
			for (auto i : v)
				mn[r] = i, r++, s.erase(i);
		}
		ans++;
	}
	cout << ans - 1 << endl;
	return 0;
}
