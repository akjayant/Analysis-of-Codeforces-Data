#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define MP make_pair

typedef long long ll;

const int N = 2e3 + 100;

struct node {
	ll v, i, op, u;
	node() {}
	node(ll v, ll i, ll op, ll u):v(v), i(i), op(op), u(u) {}
};

bool operator < (node a, node b) {
	if (a.v == b.v) return a.op > b.op;
	return a.v > b.v;
}

int n; 
int xx[N], yy[N], cc[N], kk[N];
ll dis[N];
bool vis[N];
vector<int> G;
vector<pair<int, int> > V;

int main() {
	//freopen("0.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", xx + i, yy + i);
	for (int i = 1; i <= n; i++) scanf("%d", cc + i);
	for (int i = 1; i <= n; i++) scanf("%d", kk + i);
	for (int i = 1; i <= n; i++) dis[i] = 1e18;
	priority_queue<node> Q;
	for (int i = 1; i <= n; i++) Q.push(node(cc[i], i, 0, 0));
	ll ans = 0;
	while (!Q.empty()) {
		node x = Q.top();
		Q.pop();
		int u = x.i;
		ll c = x.v;
		if (vis[u]) continue;
		vis[u] = true;
		dis[u] = c;
		ans += c;
		if (x.op == 0) G.push_back(u);
		else V.push_back(MP(u, x.u));
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			ll d = 1LL * (abs(xx[u] - xx[i]) + abs(yy[u] - yy[i])) * (kk[u] + kk[i]);
			if (dis[i] > d) {
				dis[i] = d;
				Q.push(node(d, i, 1, u));
			}
		}
	}
	printf("%lld\n", ans);
	printf("%d\n", G.size());
	for (int i = 0; i < G.size(); i++) printf("%d%c", G[i], i == G.size() - 1 ? '\n' : ' ');
	printf("%d\n", V.size());
	for (int i = 0; i < V.size(); i++) printf("%d %d\n", V[i].first, V[i].second);
	return 0;
}