#include <bits/stdc++.h>
#define ii pair <int, int>
#define x first
#define y second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << " _ " <<

using namespace std;

const int N = 1e5 + 7;

int n, m;
vector <int> adj[N];
set <int> nodes;

void bfs(int u) {
    queue <int> q;
    nodes.erase(u); q.push(u);

    while (!q.empty()) {
        int u = q.front(); 
        q.pop(); 
        
        vector<int> vis;
        for (auto it = nodes.begin(); it != nodes.end(); it++)
        	if (!binary_search(adj[u].begin(), adj[u].end(), *it)) {
	            vis.push_back(*it);
	            q.push(*it);
	        }

	    for (int x: vis)
	    	nodes.erase(x);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());

	for (int i = 1; i <= n; i++) 
		nodes.insert(i);

	int comp = 0;

	while (!nodes.empty()){
		comp++;
		bfs(*nodes.begin());
	}

	cout << comp - 1;
}