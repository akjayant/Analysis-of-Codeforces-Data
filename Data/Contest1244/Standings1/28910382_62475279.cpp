#pragma GCC optimize("2,Ofast,inline")
#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int, int>
using namespace std;
const int N = 1e5 + 10;
const LL inf = 0x3f3f3f3f3f3f3f3f;

template <typename T> T read(T &x) {
	int f = 0;
	register char c = getchar();
	while (c > '9' || c < '0') f |= (c == '-'), c = getchar();
	for (x = 0; c >= '0' && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + (c ^ 48);
	if (f) x = -x;
	return x;
}

int n, E, tot;
int c[N][3], col[N], to[N];
int fir[N], nex[N << 1], arr[N << 1], deg[N];
LL f[N][3], g[N][3];
int a[N], d[N];

inline void Add_Edge(int x, int y) {
	nex[++E] = fir[x];
	fir[x] = E; arr[E] = y;
	++deg[x];
}

void dfs(int x, int fa) {
	a[++tot] = x;
	for (int i = fir[x]; i; i = nex[i]) {
		if (arr[i] == fa) continue;
		dfs(arr[i], x);
	}
}

void solve(int x, int c) {
	col[x] = c;
	if (g[x][c]) {
		solve(to[x], g[x][c]);
	}
}

int main() {
	read(n);
	for (int j = 0; j < 3; ++j) {
		for (int i = 1; i <= n; ++i) {
			read(c[i][j]);
		}
	}
	if (n == 1) {
		int x = 0;
		for (int i = 1; i < 3; ++i) if (c[1][i] < c[1][x]) x = i;
		cout << c[1][x] << endl;
		cout << x + 1 << endl;
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		int x, y;
		read(x); read(y);
		Add_Edge(x, y);
		Add_Edge(y, x);
	}
	for (int i = 1; i <= n; ++i) {
		if (deg[i] >= 3) return 0 * puts("-1");
	}
	int pos = 0;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 1) {
			dfs(i, 0);
			pos = i;
			break;
		}
	}
	int s1 = 0, s2 = 0;
	LL ans = inf;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == j)  continue;
			LL cost = 0;
			d[1] = i; d[2] = j;
			cost += c[a[1]][i] + c[a[2]][j];
			for (int k = 3; k <= n; ++k) {
				d[k] = 3 - d[k - 1] - d[k - 2];
				cost += c[a[k]][d[k]];
			}
//			cout << i << ' ' << j << ' ' << cost << endl;
			if (cost < ans) {
				ans = cost;
				s1 = i, s2 = j;
			}
		}
	}
	// for (int i = 1; i <= n; ++i)
	// 	cout << a[i] << ' ';
	// puts("");
	// cout << s1 << ' ' << s2 << endl;
	cout << ans << endl;
	d[1] = s1; d[2] = s2;
	col[a[1]] = s1; col[a[2]] = s2;
	for (int i = 3; i <= n; ++i) {
		d[i] = 3 - d[i - 1] - d[i - 2];
		col[a[i]] = d[i];
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", col[i] + 1);
	puts("");
	return 0;
}
