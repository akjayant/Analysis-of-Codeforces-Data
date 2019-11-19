#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int maxn = 2e3 + 10, inf = 1e9;
int n, x[maxn], y[maxn], k[maxn], dp[maxn], upd[maxn], power[maxn], cnt, e;
bitset <maxn> mark;
pii p[maxn];
ll ans;

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(upd, -1, sizeof(upd));
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	for (int i = 0; i < n; ++i)
		cin >> dp[i];
	for (int i = 0; i < n; ++i)
		cin >> k[i];
	for (int t = 0; t < n; ++t) {
		pii mn = {inf, inf};
		for (int i = 0; i < n; ++i)
			if (!mark[i])
				mn = min(mn, {dp[i], i});
		int v = mn.second;
		mark[v] = true;
		ans += dp[v];
		if (~upd[v])
			p[e++] = {v, upd[v]};
		else
			power[cnt++] = v;
		for (int i = 0; i < n; ++i)
			if (!mark[i]) {
				ll val = abs(x[v] - x[i]) + abs(y[v] - y[i]);
				val *= k[i] + k[v];
				if (val < dp[i]) {
					dp[i] = val;
					upd[i] = v;
				}
			}
	}
	cout << ans << '\n' << cnt << '\n';
	for (int i = 0; i < cnt; ++i)
		cout << power[i] + 1 << ' ';
	cout << '\n' << e << '\n';
	for (int i = 0; i < e; ++i)
		cout << p[i].first + 1 << ' ' << p[i].second + 1 << '\n';
	return 0;
}
