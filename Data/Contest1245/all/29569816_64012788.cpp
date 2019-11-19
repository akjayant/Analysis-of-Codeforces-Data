#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int n;
ll x[2015], y[2015], k[2015], c[2015];
bool ok[2015];
int pre[2015];
vector<pii> res;
priority_queue<pli, vector<pli>, greater<pli> > que;
ll dis[2015];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld", &x[i], &y[i]);
	}
	for (int i = 1; i <= n; ++i) scanf("%lld", &c[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &k[i]);
	for (int i = 1; i <= n; ++i) {
		dis[i] = c[i];
		que.push(pli(dis[i], i));
	}
	ll ans = 0;
	while (que.size()) {
		pli pp = que.top(); que.pop();
		ll d = pp.first; int u = pp.second;
		if (ok[u]) continue;	
		ans += d;
		if (d == c[u]) {
			pre[u] = 0;
		} else {
			res.pb(pii(u, pre[u]));
		}
		for (int v = 1; v <= n; ++v) {
			if (ok[v] || u == v) continue;
			ll cost = (k[u] + k[v]) * (abs(x[u] - x[v]) + abs(y[u] - y[v]));
			if (cost < dis[v]) {
				dis[v] = cost;
				pre[v] = u;
				que.push(pli(dis[v], v));
			}
		}
		ok[u] = true;
	}
	printf("%lld\n", ans);
	printf("%d\n", n - (int)res.size());
	for (int i = 1; i <= n; ++i) {
		if (pre[i] == 0) printf("%d ", i);
	}
	puts("");
	printf("%d\n", (int)res.size());
	for (auto p : res) {
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}
