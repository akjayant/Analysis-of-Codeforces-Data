#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int n;
int x[maxn], y[maxn];
int c[maxn], k[maxn];
long long d[maxn][maxn];
long long dist[maxn];
bool vis[maxn];
int p[maxn];

long long prim(int s) {
	for (int i = 1; i <= n; ++i) {
		dist[i] = 2e18;
	}
	p[s] = -1;
	dist[s] = 0;
	for (int i = 0; i <= n; ++i) {
		long long mn = 2e18;
		int v = -1;
		for (int j = 0; j <= n; ++j) {
			if (not vis[j] and dist[j] < mn) {
				mn = dist[j];	
				v = j;
			}
		} 
		if (v == -1) break;
		vis[v] = 1;
		for (int j = 0; j <= n; ++j) {
			if (not vis[j] and d[v][j] < dist[j]) {
				dist[j] = d[v][j];
				p[j] = v;
			}
		}
	}
	long long res = 0;
	for (int i = 0; i <= n; ++i) res += dist[i];
	cout << res << endl;
	int t = 0;
	for (int i = 0; i <= n; ++i) if (p[i] == 0) t += 1;
	cout << t << endl;
	for (int i = 0; i <= n; ++i) {
		if (p[i] == 0) cout << i << " ";
	} cout << endl;
	vector<pair<int, int>> edges;
	for (int i = 1; i <= n; ++i) {
		if (p[i] != 0) edges.push_back({p[i], i});
	}
	cout << edges.size() << endl;
	for (auto e : edges) {
		cout << e.first << " " << e.second << endl;
	}
	return res;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> d[0][i];
		d[i][0] = 2e18;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			d[i][j] = (k[i] + k[j]) *1ll* (abs(x[i] - x[j]) + abs(y[i] - y[j]));
		}
	}
	prim(0);
	return 0;
}