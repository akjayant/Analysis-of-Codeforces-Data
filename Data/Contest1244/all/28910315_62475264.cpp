#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

const int N = 1e5 + 5;
const ll inf = 1e18;
int n, s, t, tr[3][3], co[3][N], col[N], tmp[N];
ll ans, res;
vector <int> g[N];
void add (int x, int y) {
	g[x].push_back(y);
}
ll dfs (int x, int p, int c, int d) {
	ll ret = co[c][x];
	col[x] = c;
	for (auto y : g[x]) {
		if (y != p) {
			return ret + dfs(y, x, tr[c][d], c);
		}
	}
	return ret;
}
void go (int x, int p) {
	printf("%d ", tmp[x] + 1);
	for (auto y : g[x]) {
		if (y != p) {
			go(y, x);
		}
	}
}
int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &co[0][i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &co[1][i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &co[2][i]);
	}
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	for (int i = 1; i <= n; ++i) {
		if ((int)g[i].size() > 2) {
			return puts("-1"), 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if ((int)g[i].size() == 1) {
			s = i, t = g[i][0];
			break;
		}
	}
	tr[0][1] = tr[1][0] = 2;
	tr[1][2] = tr[2][1] = 0;
	tr[0][2] = tr[2][0] = 1;
	ans = inf;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i != j) {
				col[s] = i;
				res = co[i][s] + dfs(t, s, j, i);
				if (ans > res) {
					ans = res;
					memcpy(tmp, col, sizeof tmp);
				}
				ans = min(ans, res);
			}
		}
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", tmp[i] + 1);
	}
	puts("");
	return 0;
}