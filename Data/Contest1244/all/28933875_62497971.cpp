#include <bits/stdc++.h>
#define int long long
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 1e5 + 5;
int n, c[N][3], finalCol[N];
vector<int> g[N];
vector<int> path;
void dfs(int u, int p) {
	path.pb(u);
	fa (v, g[u]) if (v != p) dfs(v, u);
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	fw (i, 0, 3) fw (j, 0, n) cin >> c[j][i];
	fw (i, 1, n) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v), g[v].pb(u);
	}
	fw (i, 0, n) if (g[i].size() >= 3) {
		cout << "-1";
		return 0;
	}
	fw (i, 0, n) if (g[i].size() == 1) {
		dfs(i, -1);
		break;
	}
	int res = infll, lol[3];
	fw (col1, 0, 3) fw (col2, 0, 3) fw (col3, 0, 3) {
		if (col1 == col2 || col2 == col3 || col1 == col3) continue;
		int col[3] = {col1, col2, col3}, ans = 0;
		fw (j, 0, n) {
			ans += c[path[j]][col[j % 3]];
		}
		if (ans < res) {
			res = ans;
			fw (j, 0, 3) lol[j] = col[j];
		}
	}
	cout << res << "\n";
	fw (j, 0, n) finalCol[path[j]] = lol[j % 3];
	fw (j, 0, n) cout << finalCol[j] + 1 << " ";
	return 0;
}