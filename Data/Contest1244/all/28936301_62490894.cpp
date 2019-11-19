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

const int N = 2e6 + 233;
int n, K, p[N], a[N];

signed main(void) {
	read(n); read(K);
	// cerr << n << " " << K << "\n";
	int down = n * (n + 1) / 2;
	int up = 0;
	for (int i = 1; i <= n; i++)
		up += max(i, n - i + 1);
	// cerr << down << " " << up << "\n";
	if (K < down) {
		cout << -1 << "\n";
		return 0;
	}
	if (K > up) K = up;
	if (n < 5) {
		rep (i, n) p[i] = i;
		int mx = 0;
		do {
			int ans = 0;
			rep (i, n) ans += max(i, p[i]);
			if (ans <= K) mx = max(mx, ans);
		} while (next_permutation(p + 1, p + n + 1));
		rep (i, n) p[i] = i;
		do {
			int ans = 0;
			rep (i, n) ans += max(i, p[i]);
			if (ans == mx) {
				cout << mx << "\n";
				rep (i, n) cout << i << " \n"[i == n];
				rep (i, n) cout << p[i] << " \n"[i == n];
				int t = 0;
				rep (i, n) t += max(i, p[i]);
				assert(t == mx);
				return 0;
			}
		} while (next_permutation(p + 1, p + n + 1));
		return 0;
	}
	int cur = down;
	rep (i, n) a[i] = i;
	int l, r;
	for (int i = 1; i < n - i + 1; i++) {
		l = i; r = n - i + 1;
		if (6 >= r - l + 1) break;
		if (cur + r - l < K) {
			cur += r - l;
			swap(a[l], a[r]);
		}
	}
	int len = r - l + 1;
	// cout << "len = " << len << "\n";
	// cout << "cur = " << cur << "\n";
	// rep (i, n) cout << a[i] << " \n"[i == n];
	rep (i, len) p[i] = i;
	do {
		int delta = 0;
		rep (i, len) delta += max(p[i], i) - i;
		if (delta == K - cur) {
			cout << K << "\n";
			rep (i, n) cout << i << " \n"[i == n];
			rep (i, len) a[i + l - 1] = p[i] + l - 1;
			rep (i, n) cout << a[i] << " \n"[i == n];
			int t = 0;
			rep (i, n) t += max(a[i], i);
			assert(t == K);
			return 0;
		}
	} while (next_permutation(p + 1, p + len + 1));
	assert(0);
}
