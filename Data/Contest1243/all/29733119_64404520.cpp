/* Apaar */

#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

vector<int> gr[N];

struct dsu {
	vector<int> p, sz;
	void init(int NN) {
		sz.clear(); p.clear();
		p.resize(NN); sz.resize(NN, 1);
		iota(p.begin(), p.end(), 0);
	}
	int get(int x) {
		return (x == p[x] ? x : (p[x] = get(p[x])));
	}
	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (sz[x] > sz[y]) {
			swap(x, y);
		}
		if (x != y) {
			p[x] = y;
			sz[y] += sz[x];
			sz[x] = 0;
		}
	}
} G;

set<int> remaining;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> m;
		for (i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			gr[x].pb(y);
			gr[y].pb(x);
		}
		for (i = 1; i <= n; i++) {
			sort(gr[i].begin(), gr[i].end());
		}
		G.init(n + 1);
		for (i = 1; i <= n; i++) {
			remaining.insert(i);
		}
		for (i = 1; i <= n; i++) {
			if (remaining.find(i) == remaining.end()) {
				continue;
			}
			cnt++;
			set<int> now;
			now.insert(i);
			while (!now.empty()) {
				int cur = *now.begin();
				remaining.erase(cur);
				now.erase(cur);
				set<int> nxt;
				for (auto x : remaining) {
					if (!binary_search(gr[cur].begin(), gr[cur].end(), x)) {
						nxt.insert(x);
					}
				}
				for (auto x : nxt) {
					remaining.erase(x);
					now.insert(x);
				}
			}
		}
		cout << cnt - 1;
	}
}