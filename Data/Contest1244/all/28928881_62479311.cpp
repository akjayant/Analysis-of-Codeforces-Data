#include<bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 7;
const int N = 100000 + 10;
int n, c[N][3];
vector<int> to[N];
int s, d[3], e[N], f[N];
long long ans, now;

void dfs(int u, int fa, int dpt)
{
	e[u] = d[dpt%3]+1;
	now += c[u][d[dpt%3]];
	for (int i = 0, sz = to[u].size(); i < sz; ++ i){
		int v = to[u][i];
		if (v == fa) continue;
		dfs(v, u, dpt+1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> c[i][0];
	for (int i = 1; i <= n; ++ i) cin >> c[i][1];
	for (int i = 1; i <= n; ++ i) cin >> c[i][2];
	for (int i = 1; i < n; ++ i){
		int x, y;
		cin >> x >> y;
		to[x].push_back(y);
		to[y].push_back(x);
	}
	for (int i = 1; i <= n; ++ i){
		if (to[i].size() > 2){
			cout << "-1" << endl;
			return 0;
		}
		if (to[i].size() == 1) s = i;
	}
	ans = inf;
	for (int i = 0; i < 3; ++ i)
		for (int j = 0; j < 3; ++ j)
			for (int k = 0; k < 3; ++ k){
				if (i == j || j == k || k == i) continue;
//				cout << i << " " << j << " " << k << endl;
				d[0] = i; d[1] = j; d[2] = k;
				now = 0;
				dfs(s, 0, 0);
				if (now < ans){
					ans = now;
					for (int o = 1; o <= n; ++ o)
						f[o] = e[o];
				}
			}
	cout << ans << endl;
	for (int i = 1; i <= n; ++ i)
		cout << f[i] << " ";
	cout << endl;
	return 0;
}