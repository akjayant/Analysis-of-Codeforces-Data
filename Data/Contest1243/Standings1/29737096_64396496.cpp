// In The Name Of GOD
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define inf 1061109567

const int MAXN = 2e5 + 15;
vector<vector<int>> comp;
int n, m;
int mx = inf, id;
int cnt;
vector<int> adj[MAXN], mem;
bool mark[MAXN];
set<int> st, mst;
queue<int> q;

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cerr << "HELLO WORLD :)\n";
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;   cin >> u >> v;
		u--, v--;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int i = 0; i < n; i++)
		st.insert(i);
	while (cnt != n) {
		int v = *st.begin();
		mem.clear();
		mem.push_back(v);
		st.erase(v);
		q.push(v);
		mark[v] = true;
		while (!q.empty()) {
			mst.clear();
			int u = q.front();
			q.pop();
			for (auto rex : adj[u])
				if (!mark[rex])
					mst.insert(rex);
			for (auto rex : st)
				if (!mst.count(rex)) {
					mem.push_back(rex);
					if (!mark[rex]) {
						q.push(rex);
						mark[rex] = true;
					}
				}
			st.swap(mst);
		}
		cnt += (int)mem.size();
		comp.push_back(mem);
	}
	sort(comp.begin(), comp.end(), [](auto x, auto y) {
		return x.size() < y.size();
		});
	return cout << comp.size() - 1 << '\n', false;
}