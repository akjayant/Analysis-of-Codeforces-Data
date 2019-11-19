#include<bits/stdc++.h>
#define pb(x)push_back(x)
#define all(x) x.begin(), x.end()
#define cout2(x, y) cout << x << " " << y << endl
#define cout3(x, y, z) cout << x << " " << y << " " << z << endl
#define N 2001
#define MOD 1000000007

using namespace std;

int x[N], y[N], c[N], k[N], parent[N];
long long current[N];
bool vis[N];

long long dist(int u, int v){
	
	long long d = abs(x[u] - x[v]) + abs(y[u] - y[v]);
	return d * (k[u] + k[v]);
}

int main(){	
	
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)cin >> x[i] >> y[i];
	for(int i = 0; i < n; i++)cin >> c[i];
	for(int i = 0; i < n; i++)cin >> k[i];
	
	for(int i = 0; i < n; i++)current[i] = c[i], parent[i] = i;
	long long ans = 0;
	
	vector<pair<int, int> >edges;
	vector<int>powers;
	
	for(int i = 0; i < n; i++){
		
		long long mini = (1LL<<61), aux, node;
		for(int j = 0; j < n; j++)if(!vis[j] && mini > current[j])mini = current[j], node = j;
		
		vis[node] = true;
		ans += current[node];
		
		if(parent[node] == node)powers.pb(node);
		else edges.pb(make_pair(parent[node], node));
		
		for(int j = 0; j < n; j++){
			
			if(vis[j])continue;
			aux = dist(node, j);
			if(!vis[j] && aux < current[j])current[j] = aux, parent[j] = node;
		}
	}
	
	cout << ans << endl;
	cout << powers.size() << endl;
	
	for(int i = 0; i < powers.size(); i++){
		
		if(i)cout << " ";
		cout << powers[i] + 1;
	}
	
	cout << endl;
	cout << edges.size() << endl;
	for(int i = 0; i < edges.size(); i++)cout << edges[i].first + 1 << " " << edges[i].second + 1 << endl; 
	
}	
