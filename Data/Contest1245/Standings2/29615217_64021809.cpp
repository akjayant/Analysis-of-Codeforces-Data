#include <bits/stdc++.h>
using namespace std;
 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define left  (2*idx)+1
#define right (2*idx)+2
#define pb push_back
#define ll long long
#define all(x) x.begin(),x.end()
 

const ll MOD = (ll)(1e9 + 7); 
const ll N = 2007;

int x[N], y[N];
int k[N];
int c[N];
ll dist[N][N];
int vis[N];

void init() {
	for(int i=1; i<N; i++) {
		vis[i] = 0;
	}
}
ll distance(int i, int j) {
	ll tmp = abs(x[i] - x[j]) + abs(y[i] - y[j]);
	return (tmp * (k[i] + k[j]));
}

int main()
{
	FIO;
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> x[i] >> y[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> c[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> k[i];
	}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			dist[i][j] = distance(i, j);
		}
	}

	ll cst = 0;
	vector<int> ans1;
	vector<pair<int, int>> ans2;
	priority_queue<pair<pair<ll, int>, int>> q;
	
	for(int j=1; j<=n; j++) {
		q.push({{-c[j], j}, -1});
	}
	

	while(!q.empty()) {
		pair<pair<ll, int>, int> f = q.top(); q.pop();
		ll tmp = -f.first.first;
		int u = f.first.second;
		int v = f.second;
		// cerr << u << " " << v << "\n";
		if(vis[u] == 1) {
			continue;
		}
		cst+=tmp;
		vis[u] = 1;
		for(int i=1; i<=n; i++) {
			if(vis[i]!=1) {
				q.push({{-dist[i][u], i}, u});
			}
		}
		if(v == -1) {
			ans1.push_back(u);
		} else {
			ans2.push_back({u, v});
		}
	}
	cout << cst << "\n";
	cout << ans1.size() << "\n";
	for(auto i : ans1) {
		cout << i << " ";
	} cout << "\n";
	cout << ans2.size() << "\n";
	for(auto i : ans2) {
		cout << i.first << " " << i.second << "\n";
	}
	return 0;	
}	