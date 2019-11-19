#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define DB( x ) cout << #x << " = " << x << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
//typedef vector <vector <ll>> matrix;

const ll MOD = (ll)(1e9 + 7);
const ll MAXV = (ll)(2e3 + 10);
const int MAX = 3e6 + 100;
const ll MAXE = (ll)(4e5 + 10);

typedef long double T;
typedef long double TT;
const ll INF = (ll)(1e9);
const TT EPS = (1e-8);

int n;
vector<pair<ll , ll>> A;
ll C[MAXV], K[MAXV];

vector<pair<int, ll>>G[MAXV];

ll dist(pair<ll, ll> a, pair<ll, ll> b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool mark[MAXV];
vector<pair<int, int>> edges;

ll prim(){
	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>> , greater<pair<ll, pair<int, int>>>> Q;


	Q.push(make_pair(0LL, make_pair(0, -1)));
	ll result = 0;
	ll w;
	while(!Q.empty()){
		int u = Q.top().second.first;
		int p = Q.top().second.second;
		w = Q.top().first;
		Q.pop();

		if(mark[u])
			continue;

		mark[u] = true;
		if(p != -1)
			edges.push_back(make_pair(min(u, p), max(u, p)));

		result += w;

		for(int i = 0; i< G[u].size();i ++){
			int v = G[u][i].first;
			if(!mark[v]){
				Q.push(make_pair(G[u][i].second, make_pair(v, u)));
			}
		}
	}

	return result;
}

int main(){
	cin.sync_with_stdio(0);cin.tie(0);

	cin >> n;

	A.resize(n);

	for(int i = 0;i < n;i ++){
		cin >> A[i].first >> A[i].second;
	}

	for(int i = 0; i< n;i ++)
		cin >> C[i];

	for(int i = 0;i < n;i ++)
		cin >> K[i];

	for(int i = 0;i < n;i ++){

		for(int j = i + 1;j < n;j ++){
			ll d = dist(A[i], A[j]);
			G[i].push_back(make_pair(j, d * (K[i] + K[j])));
			G[j].push_back(make_pair(i, d * (K[i] + K[j])));
		}
		G[i].push_back(make_pair(n, C[i]));
		G[n].push_back(make_pair(i, C[i]));
	}

	ll ans = prim();

	cout << ans << "\n";

	vector<int> station;
	vector<pair<int, int>> net;

	for(int i = 0;i < edges.size();i ++){
		if(edges[i].second == n){
			station.push_back(edges[i].first);
		}
		else{
			net.push_back(edges[i]);
		}
	}

	cout << station.size() << "\n";
	if(station.size() > 0){
		cout << station[0] + 1;
	}
	for(int i = 1;i < station.size();i ++){
		cout << " " << station[i] + 1;
	}

	if(station.size())
		cout << "\n";

	cout << net.size() << "\n";

	for(int i = 0;i < net.size();i ++){
		cout << net[i].first + 1 << " " << net[i].second + 1 << "\n";
	}
}
