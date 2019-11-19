#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1E5+2;
const int INF = 1E16;

vector<int> cost[3];
vector<vector<int> > g;
vector<int> a;
int f[MAXN][3][3][3], color[MAXN];
int n;

int dp(int i, int c2, int c1, int c0){
	int& ret = f[i][c2][c1][c0];
	if(ret != -1) return ret;
	if(c2 == c1 || c0 == c1 || c2 == c0) return ret = INF;
	if(i==n-1) return ret = 0;
	ret = INF;
	for(int c = 0; c< 3; ++c){
		if(c == c1 || c==c0) continue;
		ret = min(ret, cost[c][a[i+1]] + dp(i+1, c1, c0, c));
	}
	return ret;
}

void trace(int i, int c2, int c1, int c0){
	if(i==n-1) return;
	int c = 0, ret = INF;
	for(int x = 0; x < 3; ++x){
		if(x == c1 || x == c0) continue;
		if(dp(i+1, c1, c0, x) + cost[x][a[i+1]] < ret){
			c = x;
			ret =dp(i+1, c1, c0, x) + cost[x][a[i+1]];
		}
	}
	color[a[i+1]] = c;
	trace(i+1, c1, c0, c);
}

void dfs(int u, int p){
	if((int)g[u].size() > 2){
		cout << "-1";
		exit(0);
	}
	a.push_back(u);
	for(int v : g[u]){
		if(v==p) continue;
		dfs(v, u);
	}
}

signed main(){
	cin >> n;
	for(int i=0; i< 3; ++i) cost[i].assign(n, 0);
	for(int i=0; i< 3; ++i)
		for(int j=0; j < n; ++j) cin >> cost[i][j];
	g.assign(n, vector<int>());
	for(int i=1; i< n; ++i){
		int u, v; cin >> u >> v;
		--u; --v;
		g[u].push_back(v); g[v].push_back(u);
	}
	for(int i=0; i< n; ++i){
		if((int)g[i].size()==1){
			dfs(i, -1);
			break;
		}
	}
	memset(f, -1, sizeof f);
	memset(color, -1, sizeof color);
	int ans = INF;
	for(int x =0 ;x < 3; ++x)
		for(int y= 0; y < 3; ++y)
			for(int z=0; z < 3; ++z)
				if(dp(2, x, y, z) + cost[x][a[0]] + cost[y][a[1]] + cost[z][a[2]] < ans){
					ans = dp(2, x, y, z)+ cost[x][a[0]] + cost[y][a[1]] + cost[z][a[2]];
					color[a[0]] = x; color[a[1]] = y; color[a[2]] = z;
				}
	trace(2, color[a[0]], color[a[1]], color[a[2]]);
	cout << ans << "\n";
	for(int i=0; i< n; ++i) cout << color[i]+1 << " ";
}
