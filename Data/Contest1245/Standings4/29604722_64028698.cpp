#include "bits/stdc++.h"
#define N 2000
using namespace std;
typedef long long ll;
typedef pair<ll, int> point;
int abs(int x) { return x >= 0 ? x : -x; }
int au[N + 5], av[N + 5], c[N + 5], father[N + 5], acnt = 0,
	x[N + 5], y[N + 5], k[N + 5], n;
bool vis[N + 5];
ll ans = 0, dis[N + 5], mp[N + 5][N + 5];
void Prim() {
	for (int i = 1; i <= n; i++) dis[i] = c[i], father[i] = n + 1;
	for (int i = 1, u = n + 1; i <= n; i++) {
		int v;
		for (int j = 1; j <= n; j++)
			if (!vis[j]) {
				if (dis[j] > mp[u][j]) dis[j] = mp[u][j], father[j] = u;
				v = j;
			}
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dis[j] < dis[v]) 
				v = j;
		if (father[v] != n + 1) au[++acnt] = father[v], av[acnt] = v;
		ans += dis[v], vis[v] = 1, u = v;
	}
}
int main(int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", x + i, y + i);
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	for (int i = 1; i <= n; i++) scanf("%d", k + i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			mp[i][j] = (k[i] + k[j]) * 1ll * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
	for (int i = 1; i <= n; i++) mp[n + 1][i] = c[i];
	Prim();
	printf("%lld\n", ans);
	printf("%d\n", n - acnt);
	for (int i = 1; i <= n; i++) if (father[i] == n + 1) printf("%d ", i); puts("");
	printf("%d\n", acnt);
	for (int i = 1; i <= acnt; i++) printf("%d %d\n", au[i], av[i]);
	return 0;
}