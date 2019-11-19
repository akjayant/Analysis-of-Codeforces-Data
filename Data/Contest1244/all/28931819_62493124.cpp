#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define Local
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

int n;
int c[3][N];
int a[N], d[N], color[N], tmp[N];
vector <int> g[N];
int T;

void dfs(int u, int fa) {
	a[++T] = u;
	for(auto v : g[u]) {
		if(v == fa) continue;
		dfs(v, u);
	}
}

void run() {
	for(int i = 1; i <= n; i++) {
		d[i] = 0;
		g[i].clear();
	}
	T = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		++d[u], ++d[v];
		g[u].push_back(v), g[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		if(d[i] >= 3) {
			cout << -1 << '\n';
			return;
		}
	}
	int rt;
	for(int i = 1; i <= n; i++) {
		if(d[i] == 1) rt = i;
	}
	dfs(rt, 0);
	int col[3] = {0, 1, 2};
	ll ans = 1e18;
	do {
		ll res = 0;
		for(int i = 1; i <= n; i++) {
			res += c[col[(i - 1) % 3]][a[i]];
			tmp[a[i]] = col[(i - 1) % 3];
		}
		if(res < ans) {
			ans = res;
			memcpy(color, tmp, sizeof(color));
		}
	} while(next_permutation(col, col + 3));
	cout << ans << '\n';
	for(int i = 1; i <= n; i++) cout << color[i] + 1 << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
#ifdef Local
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#endif
    while(cin >> n) run();
    return 0;
}
