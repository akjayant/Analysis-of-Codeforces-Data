/* */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#ifdef XVENOM
	#define errp(...) fprintf(stderr, __VA_ARGS__)
#else
	#define errp(...)
#endif
#define dbg(x) errp("%s = %s\n", #x, to_string(x).data())
string to_string (string s) { return "\"" + s + "\""; }
template<typename T> string to_string (vector<T>);
template<typename U, typename V> string to_string (pair<U, V> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template<typename T> string to_string (vector<T> v) { string r = "["; for (int i = 0; i < (int)v.size() - 1; i++) r += to_string(v[i]) + ", ";
	if (!v.empty()) r += to_string(v.back()); return r + "]"; }

const int N = 2010;
ll dist[N][N], n, x[N], y[N], c[N], k[N];

struct UD {
	vi r, p;
	UD (int _n) {
		r.assign(_n + 1, 0);
		p.assign(_n + 1, 0);
		for (int i = 0; i <= _n; i++) p[i] = i;
	}
	int findSet (int i) { return (i == p[i]) ? i : (p[i] = findSet(p[i])); }
	bool sameSet (int i, int j) { return findSet(i) == findSet(j); }
	void unionSet (int i, int j) {
		int x = findSet(i), y = findSet(j);
		if (x == y) return;
		if (r[x] < r[y]) {
			p[x] = y;
		}
		else {
			p[y] = x;
			if (r[x] == r[y]) r[x]++;
		}
	}
};

int main () { 
#ifdef XVENOM
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld%lld", &x[i], &y[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &k[i]);
	memset(dist, 0, sizeof dist);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) dist[i][j] = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
	for (int i = 1; i <= n; i++) dist[0][i] = c[i];
	UD ud (n);
	vector<pair<ll, ii>> edges;
	for (int i = 0; i <= n; i++)
		for (int j = i + 1; j <= n; j++) edges.push_back({dist[i][j], {i, j}});
	sort(begin(edges), end(edges));
	vii res;
	vi pw;
	ll ans = 0;
	int cnt = 0;
	for (int i = 0; i < (int)edges.size(); i++) {
		auto e = edges[i];
		int u = e.second.first, v = e.second.second;
		ll cost = e.first;
		if (ud.sameSet(u, v)) continue;
		ud.unionSet(u, v);
		if (u == 0) {
			pw.push_back(v);
			ans += cost;
		}
		else {
			res.push_back({u, v});
			ans += cost;
		}
		cnt++;
		if (cnt == n) break;
	}
	printf("%lld\n", ans);
	printf("%d\n", (int)pw.size());
	for (int i = 0; i < (int)pw.size(); i++) printf("%d ", pw[i]); printf("\n");
	printf("%d\n", (int)res.size());
	for (int i = 0; i < (int)res.size(); i++) printf("%d %d\n", res[i].first, res[i].second);
}