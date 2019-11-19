#include <bits/stdc++.h>

#define N 2010 

using namespace std;

typedef long long ll;

char *p1, *p2, buf[100000];

#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1 ++ )

int rd() {
	int x = 0, f = 1;
	char c = nc();
	while (c < 48) {
		if (c == '-')
			f = -1;
		c = nc();
	}
	while (c > 47) {
		x = (((x << 2) + x) << 1) + (c ^ 48), c = nc();
	}
	return x * f;
}

int fa[N], x[N], y[N], n, c[N], k[N];

ll dis[N][N];

struct Node {
	int x, y;
	ll z;
}e[N * N];

inline bool cmp(const Node &a, const Node &b) {
	return a.z < b.z;
}

int cnt;

void build_edge() {
	for (int i = 1; i <= n; i ++ ) {
		for (int j = i + 1; j <= n; j ++ ) {
			dis[i][j] = dis[j][i] = (ll)(k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
			e[ ++ cnt] = (Node) {i, j, dis[i][j]};
		}
	}
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int ans[N];

int V[N], id[N];

int main() {
	n = rd();
	ll Ans = 0;
	for (int i = 1; i <= n; i ++ ) {
		x[i] = rd(), y[i] = rd();
	}
	for (int i = 1; i <= n; i ++ ) {
		c[i] = rd();
		V[i] = c[i];
		id[i] = i;
		Ans += c[i];
	}
	for (int i = 1; i <= n; i ++ ) {
		k[i] = rd();
	}
	build_edge();
	sort(e + 1, e + cnt + 1, cmp);
	for (int i = 1; i <= n; i ++ ) {
		fa[i] = i;
	}
	for (int i = 1; i <= cnt; i ++ ) {
		int x = e[i].x, y = e[i].y;
		x = find(x), y = find(y);
		if (x != y) {
			int val = max(V[x], V[y]);
			if (val > e[i].z) {
				Ans += e[i].z - val;
				ans[ ++ ans[0]] = i;
				fa[y] = x;
				if (V[x] > V[y]) {
					id[x] = id[y];
					V[x] = V[y];
				}
			}
		}
	}
	cout << Ans << endl ;
	cout << n - ans[0] << endl ;
	for (int i = 1; i <= n; i ++ ) {
		if (find(i) == i) {
			printf("%d ", id[i]);
		}
	}
	puts("");
	cout << ans[0] << endl ;
	for (int i = 1; i <= ans[0]; i ++ ) {
		printf("%d %d\n", e[ans[i]].x, e[ans[i]].y);
	}
	return 0;
}