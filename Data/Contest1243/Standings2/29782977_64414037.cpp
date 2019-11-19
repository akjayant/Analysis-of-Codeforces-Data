#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n, m;
vector < set < int > > adj;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.in", "r", stdin); //freopen("output.txt", "w", stdout);
	cin >> n >> m;
	adj.resize(n+1);
	for(int i = 0; i < m; i++){
		int f, t;
		cin >> f >> t;
		adj[f].insert(t), adj[t].insert(f);
	}
	set < int > unvis;
	for(int i = 2; i <= n; i++){
		unvis.insert(i);
	}
	queue < int > q;
	q.push(1);
	int ans = 0;
	while(!unvis.empty()){
		if(q.empty()){
			int v = *unvis.begin();
			unvis.erase(v), q.push(v), ans++;
		}
		int v = q.front(), u; q.pop();
		for(auto uv = unvis.begin(); uv != unvis.end(); uv = unvis.upper_bound(u)){
			u = *uv;
			if(adj[v].find(u) == adj[v].end()){/// add current edge
				unvis.erase(u), q.push(u);
			}
		}

	}
	cout << ans << endl;
	return 0;
}
