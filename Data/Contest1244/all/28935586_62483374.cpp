#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
#define N (int) 2e5
using namespace std;
int input () {
	int x = 0, f = 1;
	char c = getchar ();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar ();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar ();
	}
	return f == -1 ? -x : x;
}

int n;
int c[5][N];

struct Edge {
	int v, nxt;
} edge[N<<1];
int fst[N], ecnt;
void add_edge (int u, int v) {
	edge[ecnt].v = v;
	edge[ecnt].nxt = fst[u];
	fst[u] = ecnt ++;
}
void init_e () {
	memset (fst, -1, sizeof (fst));
}

ll dp[N][5][5];

int calc (int x, int y) {
	return 6 - x - y;
}
void DP (int u, int f) {
	bool flg = false;
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) {
			if (i == j) continue;
			dp[u][i][j] = 1ll * c[i][u];
		}
	}
	for (int i = fst[u]; i != -1; i = edge[i].nxt) {
		int v = edge[i].v;
		if (v == f) continue;
		flg = true;
		DP (v, u);

		for (int a = 1; a <= 3; a ++) {
			for (int b = 1; b <= 3; b ++) {
				if (a == b) continue;
				int c = calc (a, b);
				dp[u][a][b] += dp[v][b][c];
			}
		}
	}
}

int p[N];
void out (int u, int f, int cur, int pre) {
	p[u] = cur;
	for (int i = fst[u]; i != -1; i = edge[i].nxt) {
		int v = edge[i].v;
		if (v == f) continue;
		out (v, u, pre, calc (cur, pre));
	}
}

int cnt[N];

int main () {
	init_e ();
	n = input ();
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= n; j ++) {
			c[i][j] = input ();
		}
	}
	for (int i = 1; i < n; i ++) {
		int u = input (), v = input ();
		cnt[u] ++; cnt[v] ++;
		add_edge (u, v);
		add_edge (v, u);
	}
	
	bool flg = true;
	int st;
	for (int i = 1; i <= n; i ++) {
		if (cnt[i] == 1) st = i;
		if (cnt[i] > 2) {
			flg = false;
			break;
		}
	}
	if (!flg) {
		cout << -1;
		return 0;
	}
	DP (st, 0);

	ll ans = INF;
	int cur, pre;
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) {
			if (i == j) continue;
			if (dp[st][i][j] < ans) {
				ans = dp[st][i][j];
				cur = i;
				pre = j;
			}
		}
	}

	cout << ans << endl;
	
	out (st, 0, cur, pre);
	
	for (int i = 1; i <= n; i ++) {
		cout << p[i] << " ";
	}
	cout << endl;
}
