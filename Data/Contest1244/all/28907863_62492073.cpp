#include <vector>
#include <iostream>
using namespace std;
 
#define int long long
 
const int max_n = 200 * 1000;
 
int dp[max_n][3][3];
vector<int> graph[max_n];
int cost[max_n][3];
 
 
void dfs(int v, int p) {
	bool no = true;
	for(int ui = 0; ui < graph[v].size(); ++ui) {
		int u = graph[v][ui];
		if(u != p){
			no =false;
			dfs(u, v);
			dp[v][0][1] = dp[u][1][2] + cost[v][0];
			dp[v][0][2] = dp[u][2][1] + cost[v][0];
			dp[v][1][0] = dp[u][0][2] + cost[v][1];
			dp[v][1][2] = dp[u][2][0] + cost[v][1];
			dp[v][2][0] = dp[u][0][1] + cost[v][2];
			dp[v][2][1] = dp[u][1][0] + cost[v][2];
		}
	}
	if(no) {
			dp[v][0][1] = cost[v][0];
			dp[v][0][2] =  cost[v][0];
			dp[v][1][0] =  cost[v][1];
			dp[v][1][2] =  cost[v][1];
			dp[v][2][0] =  cost[v][2];
			dp[v][2][1] = cost[v][2];
	}
}
 
signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int c = 0; c < 3; ++c){
		for (int i = 0; i < n; ++i) {
			cin >> cost[i][c];
		}
	}
	if(n == 1){
		int mn = min(min(cost[0][0], cost[0][1]),cost[0][2]);
		cout << mn << "\n";
		for (int i = 0; i < 3; ++i){
			if(cost[0][i] == mn){
				cout << i + 1;
				return 0;
			}
		}
	}
	for(int i = 0; i < n - 1; ++i){
		int a, b;
		cin >> a >> b;
		a--,b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
	{
		if(graph[i].size() > 2) {
			cout << -1;
			return 0;
		}
	}
	int root = -1;
	for (int i = 0; i < n; ++i)
	{
		if(graph[i].size() == 1) {
			root = i;
		}
	}
	dfs(root, -1);
	int mn = 100000000000000000LL;
	int x1 = -1;
	int x2 = -1;
	for(int c1 = 0; c1 < 3; ++c1){
		for(int c2 = 0; c2 < 3; ++c2) {
			if(c1 != c2 && dp[root][c1][c2] < mn) {
				x1 = c1;
				x2 = c2;
				mn = dp[root][c1][c2];
			}
		}
	}
	cout << mn << "\n";
	int first = x1;
	int second = x2;
	int ans[n];
	ans[root] = x1;
	ans[graph[root][0]] = x2;
	int now = graph[root][0];
	int prev = root;
	for(int i = 2; i < n; ++i) {
		int third = 3 - first - second;
		for(int ui = 0; ui < graph[now].size(); ++ui) {
			int u = graph[now][ui];
			if(u != prev) {
				ans[u] = third;
				prev = now;
				now = u;
				break;
			}
		}
		first = second;
		second = third;
	}
	for(int i = 0; i < n; ++i) {
		cout << ans[i] + 1 << " ";
	}
	}
