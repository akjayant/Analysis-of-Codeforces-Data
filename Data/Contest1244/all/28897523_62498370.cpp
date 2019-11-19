#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX = 100005;
const LL INFLL = 1LL<<60;

int n, c[4][MX];
vector<int> G[MX];
LL dp[10][MX];
int dpfr[10][MX];
int seq[MX], col[MX];

void dfs(int x, int fr, int dep) {
	seq[dep] = x;
	for(int v : G[x]) if(v != fr) dfs(v, x, dep + 1);
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i <= 2; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &c[i][j]);
	for(int u, v, i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for(int i = 1; i <= n; i++)
		if(G[i].size() > 2) {
			printf("-1\n");
			return 0;
		}
	for(int i = 1; i <= n; i++)
		if(G[i].size() == 1) {
			dfs(i, 0, 1);
			break;
		}
	for(int i = 0; i <= 2; i++)
		for(int j = 0; j <= 2; j++)
			if(i != j) dp[i * 3 + j][2] = c[i][seq[1]] + c[j][seq[2]];
	for(int i = 3; i <= n; i++) {
		for(int j = 0; j <= 2; j++) // cur
			for(int k = 0; k <= 2; k++) // pre
				if(j != k) 
					dp[k * 3 + j][i] = c[j][seq[i]] + dp[(3 - j - k) * 3 + k][i - 1];
	}

	LL ans = INFLL;
	for(int i = 0; i <= 2; i++)
		for(int j = 0; j <= 2; j++)
			if(i != j) ans = min(ans, dp[i * 3 + j][n]);
	printf("%lld\n", ans);
	for(int i = 0; i <= 2; i++)
		for(int j = 0; j <= 2; j++)
			if(i != j && ans == dp[i * 3 + j][n]) {
				col[seq[n]] = j;
				col[seq[n - 1]] = i;
				for(int i = n - 2; i >= 1; i--)
					col[seq[i]] = 3 - col[seq[i + 1]] - col[seq[i + 2]];
				break;
			}

	for(int i = 1; i <= n; i++)
		printf("%d ", col[i] + 1);
	return 0;
}
