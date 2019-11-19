#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)

void solve();

signed main () {
    cout.precision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1; 
    // cin >> t;
    int tt = t;
    while (t--) { 
        solve();
    }
    return 0;
}
const int N = 2005;
int sz[N], p[N];
// vector<pair<int, int>> adj[N];
vector<pair<int, pair<int, int>>> edges;
vector<pair<int, pair<int, int>>> fina;
int n;
int x[N], y[N];
vector<int> powr;
vector<pair<int, int>> conn;
int c[N], k[N];
int find (int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}
void merge (int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (sz[a] < sz[b])
		swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
}
void solve() {
    cin >> n;
    for (int i = 0; i <= n; ++i)
    	p[i] = i, sz[i] = 1;
    for (int i = 1; i <= n; ++i) {
    	cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; ++i)
    	cin >> c[i];
    for (int i = 1; i <= n; ++i)
    	cin >> k[i];
    for (int i = 1; i <= n; i += 1) {
    	edges.push_back(make_pair(c[i], make_pair(0, i)));
    }
    for (int i = 1; i <= n; ++i) {
    	for (int j = i + 1; j <= n; ++j) {
    		int dist = llabs(x[i] - x[j]) + llabs(y[i] - y[j]);
    		edges.push_back(make_pair(dist * (k[i] + k[j]), make_pair(i, j)));
    	}
    }
    int tot = 0;
    sort(edges.begin(), edges.end());
    for (auto &j : edges) {
    	int u = j.second.first; 
    	int v = j.second.second;
    	if (find(u) == find(v))
    		continue;
    	merge(u, v);
    	fina.push_back(j);
    	tot += j.first;
    }
    for (auto j : fina) {
    	if (j.second.first == 0)
    		powr.push_back(j.second.second);
    	else
    		conn.push_back({j.second.first, j.second.second});
    }
    cout << tot << '\n';
    cout << (int) powr.size() << '\n';
    for (auto i : powr)
    	cout << i << ' ';
    cout << '\n';
    cout << (int) conn.size() << '\n';
    for (auto j : conn)
    	cout << j.first << ' ' << j.second << '\n';
}       
