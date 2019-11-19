#pragma GCC optimize(2)
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
inline void read (int& s) {
	s = 0; int f = 0;
	static char c = getchar ();
	while (c < '0' || c > '9') {if (c == '-') f = 1; c = getchar ();}
	while (c >= '0' && c <= '9') s = (s << 3) + (s << 1) + (c ^ 48), c = getchar ();
	s = f ? -s : s; return ;
}

const int N = 2003;
int n, m, x[N], y[N], c[N], k[N];
struct stu {
	int fr, to;
	ll w;
	inline int operator < (const stu& p) const {
		return w < p.w;
	}
}s[N * N];

int st[N], v, fa[N];
int ano[2][N], num;

int Find (const int p) {return fa[p] == p ? p : fa[p] = Find (fa[p]);}

int main () {
	read (n);
	int i, j; for (i = 1; i <= n; ++i)
		read (x[i]), read (y[i]);
	for (i = 1; i <= n; ++i) {
		read (c[i]);
		s[++m] = (stu) {0, i, c[i]};
	}
	for (i = 1; i <= n; ++i) read (k[i]);
	for (i = 1; i < n; ++i) {
		for (j = i + 1; j <= n; ++j)
			s[++m] = (stu) {i, j, 1ll * (k[i] + k[j]) * (abs (x[i] - x[j]) + abs (y[i] - y[j]))};
	}
	sort (s + 1, s + m + 1);
	int now = 0, fx, fy;
	ll ans = 0;
	for (i = 1; i <= n; ++i) fa[i] = i;
	for (i = 1; i <= m; ++i) {
		fx = Find (s[i].fr);
		fy = Find (s[i].to);
		if (fx != fy) {
			++now;
			fa[fx] = fy;
			ans += s[i].w;
			if (!s[i].fr)
				st[++v] = s[i].to;
			else {
				++num;
				ano[0][num] = s[i].fr;
				ano[1][num] = s[i].to;
			}
			if (now == n) break;
		}
	}
	cout << ans << '\n';
	printf ("%d\n", v);
	for (i = 1; i < v; ++i) printf ("%d ", st[i]);
	printf ("%d\n", st[v]);
	printf ("%d\n", num);
	for (i = 1; i <= num; ++i) printf ("%d %d\n", ano[0][i], ano[1][i]);
	return 0;
}

