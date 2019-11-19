//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 17;
const ll inf = 1e18;

ll n, c[MAXN][4], ans[MAXN], sumA = inf, x;
vector<int> adj[MAXN];

void bt(int v, int c1, int c2, int par, ll sum, bool flag) {
	if (adj[v].size() == 1 && v != x) {
		for (int j = 1; j <= 3; j++) {
			if (j == c1 || j == c2)
				continue;
			ans[v] = j;
			if (flag) {
				if (sum + c[v][j] == sumA) {
					cout << sumA << endl;
					for (int i = 1; i <= n; i++)
						cout << ans[i] << " ";
					exit(0);
				}
			}
			else {
				sumA = min(sumA, sum + c[v][j]);
			}
		}
		return;
	}
	for (auto i : adj[v]) {
		if (i == par)
			continue;
		for (int j = 1; j <= 3; j++) {
			if (j == c1 || j == c2)
				continue;
			ans[v] = j;
			bt(i, j, c1, v, sum + c[v][j], flag);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= n; j++)
			cin >> c[j][i];
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() >= 3)
			return cout << -1 << endl, 0;
		if (adj[i].size() == 1)
			x = i;
	}
	bt(x, 0, 0, 0, 0, 0);
	bt(x, 0, 0, 0, 0, 1);
	return 0;
}
