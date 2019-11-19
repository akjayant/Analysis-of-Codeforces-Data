//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 15 + 2;

int n, path[(1 << MAXN)], c[MAXN], g[MAXN];
ll sum, sa[MAXN];
vector<int> a[MAXN];
map<int, int> mp;
bool dp[(1 << MAXN)], mark[(1 << MAXN)];

void mem(int mask) {
	if (mask == 0)
		dp[mask] = true; 
	if (mark[mask] || mask == 0)
		return;
	mark[mask] = true;
	int last = __builtin_ctz(mask) + 1;
	if (sa[last] == sum) {
		mem(mask ^ (1 << (last - 1)));
		dp[mask] = dp[mask ^ (1 << (last - 1))];
		path[mask] = -1;
		return;
	}
	int maskpr = mask ^ (1 << (last - 1));
	for (auto i : a[last]) {
		int tmp = last, p = i, maskp = maskpr, dade = i;
		if (sum - (sa[tmp] - dade) == p)
			continue;
		bool flag = true;
		while (flag) {
			ll need = sum - (sa[tmp] - dade);
			if (need > 1e9 || mp.count(need) == 0 || ((maskp & (1 << (mp[need] - 1))) == 0 && need != p)) {
				flag = false;
				break;
			}
			if (need == p) {
				break;
			}
			dade = need;
			tmp = mp[need];
			maskp ^= (1 << (mp[need] - 1));
		}
		if (flag) {
			mem(maskp);
			dp[mask] = dp[maskp];
		}
		if (dp[mask]) {
			path[mask] = i;
			return;
		}
	}
}

void pp(int mask) {
	if (mask == 0)
		return;
	int last = __builtin_ctz(mask) + 1;
	if (path[mask] == -1) {
		c[last] = a[last][0];
		g[last] = last;
		pp(mask ^ (1 << (last - 1)));
		return;
	}
	int tmp = last, p = path[mask], maskp = mask ^ (1 << (last - 1)), dade = path[mask];
	c[last] = path[mask];
	while (true) {

		ll need = sum - (sa[tmp] - dade);
		if (need == p) {
			g[last] = tmp;
			break;
		}
		g[mp[need]] = tmp;
		c[mp[need]] = need;
		dade = need;
		tmp = mp[need];
		maskp ^= (1 << (mp[need] - 1));
	}
	pp(maskp);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int ni, t;
		cin >> ni;
		for (int j = 1; j <= ni; j++)
			cin >> t, a[i].pb(t), sum += t, sa[i] += t, mp[t] = i;
	}
	if (sum % n)
		return cout << "No\n", 0;
	sum /= n;
	mem((1 << n) - 1);
	if (!dp[(1 << n) - 1])
		return cout << "No\n", 0;
	cout << "Yes\n";
	pp((1 << n) - 1);
	for (int i = 1; i <= n; i++)
		cout << c[i] << ' ' << g[i] << '\n';
	return 0;
}
