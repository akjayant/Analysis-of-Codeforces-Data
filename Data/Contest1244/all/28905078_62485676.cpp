#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define oo 0x3f3f3f3fLL
#define OO (oo*oo)
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> matrix;
const ld PI = acos(-1), EPS = 1e-8;
const int mod = 1000000007;
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}

vector<int> cost[3], ans;
vector<vector<int>> adj;
int color[]{ 0,1,2 };
ll dfs(int node, int par, int idx) {
	ll sum = cost[color[idx]][node];
	ans[node] = color[idx] + 1;
	for (int child : adj[node])
		if (child != par)
			sum += dfs(child, node, (idx + 1) % 3);
	return sum;
}

int main() {
	run();
	int n; cin >> n;
	ans = cost[0] = cost[1] = cost[2] = vector<int>(n + 1);
	for (int j = 0; j < 3; j++)for (int i = 1; i <= n; i++)
		cin >> cost[j][i];
	adj = vector<vector<int>>(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int root = 1;
	for (int i = 1; i <= n; i++)
		if (sz(adj[i]) > 2)RT(-1);
		else if (sz(adj[i]) == 1)root = i;
	ll res = OO, idx = 0, cnt = 0;
	do {
		ll rt = dfs(root, -1, 0);
		if (rt < res)res = rt, idx = cnt;
		cnt++;
	} while (next_permutation(color, color + 3));
	while (idx--)next_permutation(color, color + 3);
	dfs(root, -1, 0);
	cout << res << endl;
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}