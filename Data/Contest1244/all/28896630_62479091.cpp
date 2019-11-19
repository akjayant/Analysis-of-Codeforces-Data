//besmellah
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector <int> adj[maxn];
long long sum[3][3];
int ind[maxn];
long long c[3][maxn];
int deg[maxn];

void dfs(int v, int p = -1){
	for (auto u: adj[v]){
		if (u != p){
			ind[u] = (ind[v] + 1) % 3;
			dfs(u, v);
		}
	}
		sum[0][ind[v]] += c[0][v];
		sum[1][ind[v]] += c[1][v];
		sum[2][ind[v]] += c[2][v];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> c[0][i];
	for (int i = 0; i < n; i ++)
		cin >> c[1][i];
	for (int i = 0; i < n; i ++)
		cin >> c[2][i];
	for (int i = 0; i < n - 1; i ++){
		int v, u;
		cin >> v >> u;
		v --;
		u --;
		adj[v].push_back(u);
		adj[u].push_back(v);
		deg[v] ++;
		deg[u] ++;
	}
	if (*(max_element(deg, deg + n)) > 2){
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n; i ++){
		if (deg[i] == 1){
			dfs(i);
			break;
		}
	}
	vector <int> P(3), b(3);
	P = {0, 1, 2};
	long long ans = 1e18;
	do{
		if (sum[0][P[0]] + sum[1][P[1]] + sum[2][P[2]] < ans){
			b[0] = P[0];
			b[1] = P[1];
			b[2] = P[2];
			ans = sum[0][P[0]] + sum[1][P[1]] + sum[2][P[2]];
		}
	} while (next_permutation(P.begin(), P.end()));
	cout << ans << '\n';
	for (int i = 0; i < n; i ++){
		if (b[0] == ind[i])
			cout << "1 ";
		else if (b[1] == ind[i])
			cout << "2 ";
		else
			cout << "3 ";
	}
}
