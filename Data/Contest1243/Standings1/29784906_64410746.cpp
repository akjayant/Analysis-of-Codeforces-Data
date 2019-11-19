#include <bits/stdc++.h>

#define boost ios_base::sync_with_stdio(false), cin.tie(NULL);

using namespace std;
const int N = 1e6 + 55;
const int mod = 1e9 + 7;
const long long INF = 1e18 + 12;
const int inf = 1e9;

vector <int> g[N];

int deg[N];

int main () {
	boost;
	int n, m;
	cin >> n >> m;
	for (int i = 0 ; i < m ; ++ i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back (b);
		g[b].push_back (a);
	}
	set <pair <int, int> > s;
	for (int i = 0 ; i < n ; ++ i) {
		s.insert ({-g[i].size(), i});
		deg[i] = g[i].size();
	}
	int ans = 0;
	int cnt = n - 1;
	while (s.size() > 1) {
		int v = (*s.begin()).second, cur = -(*s.begin()).first;
		s.erase (s.begin());
		for (int to : g[v]) if (deg[to] > 0) {
			s.erase ({-deg[to], to});
			deg[to]--;
			s.insert ({-deg[to], to});
		}
		deg[v] = -1;
		--cnt;
		if (cur >= cnt + 1) ++ans;
		else {
			continue;
		}
	}
	cout << ans;
}