#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
using namespace std;
const long long INF = 1LL << 60;
const int maxn = 1e6 + 6;
vector <int> G[maxn];
int d[maxn], c[maxn][4], tc[maxn], ansc[maxn];
long long dfs(int u, int f, int n, int l){
	long long ans = c[u][n];
	tc[u] = n;
	for (int i = 0; i < G[u].size(); ++ i){
		int v = G[u][i];
		if (v != f)
			ans += dfs(v, u, 6 - (n + l), n);
	}
	return ans;
}
inline int read() {
    int x = 0, flag = 1;char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') flag = - 1;
        ch = getchar();
    }
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * flag;
}
int main() {   
	int n = read();
	for (int i = 1; i <= n; ++ i)
		c[i][1] = read();
	for (int i = 1; i <= n; ++ i)
		c[i][2] = read();
	for (int i = 1; i <= n; ++ i)
		c[i][3] = read();
	for (int i = 1; i < n; ++ i){
		int u = read(), v  = read();
		++ d[u], ++ d[v];
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int t = 0;
	for (int i = 1; i <= n; ++ i)
		if (d[i] > 2){
			cout << -1 << endl;
			return 0;
		}
		else if (d[i] == 1)
			t = i;
	int x = t, y = G[t][0];
	long long ans = INF;
	for (int i = 1; i <= 3; ++ i)
		for (int j = 1; j <= 3; ++ j)
			if (i != j){
				long long t = c[x][i] + dfs(y, x, j, i);
				if (t < ans){
					ans = t;
					tc[x] = i;
					for (int k = 1; k <= n; ++ k)
						ansc[k] = tc[k];
				}
			}
	cout << ans << endl;
	for (int i = 1; i <= n; ++ i)
		printf("%d ", ansc[i]);
	return 0;
}