#include <bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
const int M = 20;
#define lowbit(x) (x&(-x))
const int inf = 0x3f3f3f3f;
const ll INF = 100000000000000000;
const int mod = 998244353;
typedef pair<int, int> P;
#define eps 1e-6
int n;
vector<int> G[N];
ll col[5][N];
ll dp[N];
int c[N];
int pre[5][N];
int tot, b[N];
void dfs(int u, int fa)
{
	b[++tot] = u;
	for (auto &v : G[u]){
		if (v == fa) continue;
		dfs(v, u);
	}
}
ll DP(int x,int y)
{
	dp[1] = col[x][b[1]];
	dp[2] = col[y][b[2]]+dp[1];
	c[1] = x, c[2] = y;
	for (int i = 3; i <= n; i++){
		for (int j = 1; j <= 3; j++){
			if (j != c[i - 1] && j != c[i - 2]){
				c[i] = j;
				dp[i] = col[j][b[i]]+dp[i-1];
				break;
			}
		}
	}
	return dp[n];
}
int Col[N];
void solve(int x, int y)
{
	c[1] = x, c[2] = y;
	Col[b[1]] = x;
	Col[b[2]] = y;
	for (int i = 3; i <= n; i++){
		for (int j = 1; j <= 3; j++){
			if (j != c[i - 1] && j != c[i - 2]){
				c[i] = j;
				Col[b[i]] = j;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", Col[i]);
	}

}
P p[10] = { {0,0},{ 1, 2 }, { 1, 3 }, { 2, 1 }, { 2, 3 }, { 3, 1 }, { 3, 2 } };
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", &col[i][j]);
		}
	}
	int u, v;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (G[i].size()>2){
			return 0 * puts("-1");
		}
	}
	int root = 1;
	for (int i = 1; i <= n; i++) {
		if (G[i].size()==1){
			root = i;
			break;
		}
	}
	dfs(root, -1);
	ll ans1 = DP(1, 2);
	int res = 1;
	ll x;
	for (int i = 2; i <= 6; i++){
		x = DP(p[i].first, p[i].second);
		if (ans1 > x){
			ans1 = x;
			res = i;
		}
	}
	printf("%lld\n", ans1);
	solve(p[res].first, p[res].second);
	return 0;
}
/*

*/