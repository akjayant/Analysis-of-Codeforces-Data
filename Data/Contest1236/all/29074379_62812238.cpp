#include <bits/stdc++.h>
#define mk make_pair
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n, m, a[N], nxt[N], pre[N];
ll ans;
map<int, int> M;
int r[N], l[N], f[N], g[N];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", a + i);
		if (a[i] - i > 0) {
			if (r[a[i] - i] == 0) 
				r[a[i] - i] = i;
		}
		if (a[i] + i <= n) {
			if (l[a[i] + i] == 0)
				l[a[i] + i] = i;
		}
	}
	if (n == 1) return puts("0");
	for (int i = m; i >= 1; --i) {
		if (M.count(a[i] - i - 1))
			nxt[i] = M[a[i] - i - 1];
		M[a[i] - i] = i;
		f[i] = f[nxt[i]] + 1;
	}
	M.clear();
	for (int i = m; i >= 1; --i) {
		if (M.count(a[i] + i + 1))
			pre[i] = M[a[i] + i + 1];
		M[a[i] + i] = i;
		g[i] = g[pre[i]] + 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (r[i] == 0) {
			ans += min(n, i + m + 1);
		} else {
			int stop = f[r[i]];
			ans += min(n, i + m + 1 - stop);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (l[i] == 0) {
			ans += 1 - max(1, i - m - 1);
		} else {
			int stop = g[l[i]];
			ans += 1 - max(1, i - m - 1 + stop);
		}
	}
	cout << ans;
}

