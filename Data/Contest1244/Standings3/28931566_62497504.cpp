#include<bits/stdc++.h>
#define rint register int
#define deb(x) cerr<<#x<<" = "<<(x)<<'\n';
//#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
typedef long long ll;
using pii = pair <ll,int>;
const int maxn = 1e5 + 5;
int n;
int co[maxn];
vector <int> g[maxn];
ll c[maxn][5];
ll dp[maxn][5][5];

void dfs(int u, int f) {
	for(auto v : g[u]) {
		if(v == f) continue;
		dfs(v, u);
		dp[u][1][2] += dp[v][2][3], dp[u][1][3] += dp[v][3][2];
		dp[u][2][1] += dp[v][1][3], dp[u][2][3] += dp[v][3][1];
		dp[u][3][1] += dp[v][1][2], dp[u][3][2] += dp[v][2][1];
	}
}

void dfs1(int u, int f, int c1, int c2) {
	co[u] = c1;
	for(auto v : g[u]) {
		if(v == f) continue;
		co[v] = c2;
		int c3;
		if(c1 + c2 == 3) c3 = 3;
		if(c1 + c2 == 4) c3 = 2;
		if(c1 + c2 == 5) c3 = 1;
		dfs1(v, u, c2, c3);
	}
}

int main() {
	scanf("%d", &n);
	for(int i=1; i<4; i++)
		for(int j=1; j<=n; j++)
			scanf("%lld", &c[j][i]);
	for(int i=1; i<n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int st;
	for(int i=1; i<=n; i++)
		if(int(g[i].size()) > 2) {
			puts("-1");
			return 0;
		} else if(g[i].size() == 1) st = i;

	for(int k=1; k<=n; k++)
		for(int i=1; i<=3; i++)
			for(int j=1; j<=3; j++){
				if(i == j) continue;
				dp[k][i][j] = c[k][i];
			}

	dfs(st, 0);
	
	ll ans = 1e18;
	int st1, st2;
	for(int i=1; i<4; i++)
		for(int j=1; j<4; j++) {
			if(i == j) continue;
			if(dp[st][i][j] <= ans) st1 = i, st2 = j;
			ans = min(ans, dp[st][i][j]);
		}
	dfs1(st, 0, st1, st2);
	printf("%lld\n", ans);
	for(int i=1; i<=n; i++)
		printf("%d%c", co[i], i<n ? ' ' : '\n');
}
