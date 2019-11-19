#include <bits/stdc++.h>
#define N 100005

using namespace std;

int n;
int cnt[N];
int tmp[N][4], c[N][4];
int to[N][4], id[N], re[N], tot;
int ne[4], Ne[4];

void dfs(int u, int fa) {
	id[u] = ++tot, re[tot] = u;
	if (to[u][1] != fa) dfs(to[u][1], u);
	if (to[u][2] && to[u][2] != fa) dfs(to[u][2], u);
}

long long calc(int x, int y) {
	long long res = 0;
	res += c[1][x] + c[2][y];
	for (int i = 3, col = ne[y]; i <= n; ++i, col = ne[col])
		res += c[i][col];
	return res;
}


int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> tmp[i][1];
	for (int i = 1; i <= n; ++i) cin >> tmp[i][2];
	for (int i = 1; i <= n; ++i) cin >> tmp[i][3];

	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		to[u][++cnt[u]] = v;
		to[v][++cnt[v]] = u;
		if (cnt[u] > 2 || cnt[v] > 2) {
			cout << "-1" << endl;
			return 0;
		}
	}

	for (int i = 1; i <= n; ++i)
		if (cnt[i] == 1) {
			dfs(i, 0);
			break;
		}

	for (int i = 1; i <= n; ++i) {
		c[id[i]][1] = tmp[i][1];
		c[id[i]][2] = tmp[i][2];
		c[id[i]][3] = tmp[i][3];
	}

	long long ans = LLONG_MAX, xx, yy, Xor = 1 ^ 2 ^ 3;
	for (int x = 1; x <= 3; ++x)
		for (int y = 1; y <= 3; ++y) {
			if (x == y) continue;
			ne[x] = y, ne[y] = Xor ^ x ^ y, ne[Xor ^ x ^ y] = x;
			long long tmp = calc(x, y);
			if (tmp < ans) {
				ans = tmp, xx = x, yy = y;
				memcpy(Ne, ne, sizeof ne);
			}
		}

	static int Ans[N];
	cout << ans << endl;
	for (int i = 1, col = xx; i <= n; ++i, col = Ne[col]) Ans[re[i]] = col;
	for (int i = 1; i < n; ++i) cout << Ans[i] << ' ';
	cout << Ans[n] << endl;
	return 0;
}
