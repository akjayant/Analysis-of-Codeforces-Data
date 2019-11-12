#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int main() {
	int n = read();
	vector <vi> ans(n);
	int i = 0, d = 1;
	rep(j, n * n) {
		ans[i].pb(j);
		i += d;
		if (i < 0) i = 0, d = -d;
		if (i >= n) i = n - 1, d = -d;
	}
	rep(i, n) rep(j, n) printf("%d%c", ans[i][j] + 1, j + 1 == n ? 10 : 32);
	return 0;
}
