#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
// int lowbit(int x) {
// 	return x & (-x);
// }

// void add(int i, int x, int a) {
// 	while (x <= len) {
// 		tree[i][x] += a;
// 		x += lowbit(x);
// 	}
// }

// int ask(int i, int x) {
// 	int res = 0;
// 	while (x) {
// 		res += tree[i][x];
// 		x -= lowbit(x);
// 	}
// 	return res;
// }

int n;
int a[3][MAXN];
int q[MAXN];

vector<int> edge[MAXN];

int ans[MAXN];
int cur[MAXN];
LL sum = 0;
LL minm = 999999999999999;

int p = 0;
int sx[6][3] = {{1, 2, 3}, 1, 3, 2, 2, 1, 3, 2, 3, 1, 3, 1, 2, 3, 2, 1};
bool vis[MAXN];

void dfs(int u, int d) {
	vis[u] = 1;
	sum += a[sx[p][d] - 1][u];
	cur[u] = sx[p][d];

	for (unsigned i = 0; i < edge[u].size(); i++)
		if (vis[edge[u][i]] == 0)
			dfs(edge[u][i], (d + 1) % 3);
}


int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		q[u]++; q[v]++;
	}

	int s;
	for (int i = 1; i <= n; i++)
		if (q[i] >= 3) {
			cout << -1 << endl;
			return 0;
		} else if (q[i] == 1)
			s = i;


	for (p = 0; p < 6; p++) {
		memset(vis, 0, sizeof(vis));
		sum = 0;
		dfs(s, 0);

		if (sum < minm) {
			minm = sum;
			for (int i = 1; i <= n; i++)
				ans[i] = cur[i];
		}
	}


	cout << minm << endl;
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " \n"[i == n];

	return 0;
}