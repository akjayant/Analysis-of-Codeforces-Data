#include <bits/stdc++.h>
#define rep(i, n) for (rint i = 1; i <= (n); i ++)
#define re0(i, n) for (rint i = 0; i < (int) n; i ++)
#define travel(i, u) for (rint i = head[u]; i; i = e[i].nxt)
#define rint register int
using namespace std;

typedef long long lo;

template<typename tp> inline void read(tp &x) {
    x = 0; char c = getchar(); int f = 0;
    for (; c < '0' || c > '9'; f |= c == '-', c = getchar());
    for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
    if (f) x = -x;
}

#define int long long
const int inf = 1e16;
const int N = 3e5 + 233;
int n, w[3][N]; vector <int> G[N];
int book[N], col[N], cc[N];

signed main(void) {
	read(n);
	re0 (k, 3) rep (i, n) read(w[k][i]);
	rep (i, n - 1) {
		int x, y; read(x); read(y);
		G[x].emplace_back(y); G[y].emplace_back(x);
	}
	rep (i, n) if (G[i].size() >= 3) {
		cout << -1 << "\n";
		return 0;
	}
	int rt = -1;
	rep (i, n) if (G[i].size() == 1) { rt = i; break; }
	// cout << rt << "\n";
	vector <int> t;
	t.push_back(rt);
	book[rt] = 1;
	int u = rt;
	while (t.size() < n) {
		int to = -1;
		for (int v : G[u])
			if (!book[v]) { to = v; }
		book[to] = true;
		t.push_back(u = to);
	}
	auto calc = [&](int x, int y, int f = 0) {
		int ans = 0;
		col[1] = x; col[2] = y;
		for (int i = 3; i <= n; i++) {
			col[i] = 3 - col[i - 1] - col[i - 2];
		}
		// cout << col[3] << "\n";
		// cout << 23 << "\n";
		// cout << t[1] << " " << t[2] << " " << t[4] << "\n";
		rep (i, n) {
			// cout << i << "\n";
			ans += w[col[i]][t[i - 1]];
		}
		if (f) {
			rep (i, n) cc[t[i - 1]] = col[i];
			rep (i, n) cout << cc[i] + 1 << " \n"[i == n];
		}
		return ans;
	};
	int tx = 0, ty = 1;
	int v = calc(tx, ty);
	re0 (x, 3) re0 (y, 3) if (x != y) {
		int t = calc(x, y);
		if (t < v) {
			v = t; tx = x; ty = y;
		}
	}
	cout << v << "\n";
	calc(tx, ty, 1);
}
