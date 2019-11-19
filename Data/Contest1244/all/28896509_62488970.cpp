#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e5 + 5;
const int inf = 1e18 + 7;

int ans[N], en = 0;
vector<int> v, g[N];
int dp[N][3][3], c[N][3];

void dfs(int u, int p){
	v.push_back(u);
	for(auto i: g[u]){
		if(i != p)	
			dfs(i, u);
	}
}
 
signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> c[i][0];	
	for(int i = 1; i <= n; i++)
		cin >> c[i][1];
	for(int i = 1; i <= n; i++)
		cin >> c[i][2];
	for(int i = 1; i <= n-1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int root = 0;
	for(int i = 1; i <= n; i++){
		if((int)g[i].size() > 2)
			return cout << -1, 0;
		if((int)g[i].size() == 1)
			root = i;
	}
	v.push_back(0);
	dfs(root, 0);
	dp[1][0][1] = dp[1][0][2] = c[v[1]][0];
	dp[1][1][0] = dp[1][1][2] = c[v[1]][1];
	dp[1][2][0] = dp[1][2][1] = c[v[1]][2];
	for(int i = 2; i <= n; i++){
		for(int cj = 0; cj < 3; cj++){
			for(int d = 0; d < 3; d++){
				if(cj == d)	continue;
				dp[i][cj][d] = dp[i-1][d][3-cj-d] + c[v[i]][cj];
			}
		}
	}
	int mi = inf, id = -1, lid = -1;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++){
			if(mi > dp[n][i][j] && i != j){
				mi = dp[n][i][j];
				id = i, lid = j;
			}
		}
	cout << mi << endl;
	int cur = n;
	while(cur--){
		ans[v[cur+1]] = id;
		int temp = id;
		id = lid;
		lid = 3-temp-id;
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i]+1 << " ";
	return 0;
}