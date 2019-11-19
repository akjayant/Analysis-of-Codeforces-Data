#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;
typedef complex<ll> point;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct union_find
{
	vector<int> p;

	union_find(int n) : p(n, -1) {}

	bool join(int u, int v)
	{
		if ((u = root(u)) == (v = root(v)))
			return false;
		if (p[u] > p[v])
			swap(u, v);
		p[u] += p[v];
		p[v] = u;
		return true;
	}

	int root(int u)
	{
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
};

ll man_dist(ll x, ll y, ll xo, ll yo){
	return abs(x - xo) + abs(y - yo);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("points.in", "r", stdin);
	//freopen("output.txt", "w", stdout);

	const ll oo = 1e17;

	int n;
	cin >> n;

	union_find ds(n + 1);

	vector<ll> x(n), y(n), c(n), k(n);

	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	for(int i = 0; i < n; i++)
		cin >> c[i];

	for(int i = 0; i < n; i++)
		cin >> k[i];

	vector<pair<ll, pii>> edges;

	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			edges.push_back({(k[i] + k[j]) * man_dist(x[i], y[i], x[j], y[j]), {i, j}});

	for(int i = 0; i < n; i++)
		edges.push_back({c[i], {i, n}});

	sort(edges.begin(), edges.end());
	
	ll cost = 0;
	vector<pii> e;

	for(int i = 0; i < edges.size(); i++){
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		ll c = edges[i].first;

		if(ds.join(u, v)){
			cost += c;
			e.push_back({u, v});
		}
	}

	vector<int> ansr;
	vector<pii> real_edges;

	for(int i = 0; i < e.size(); i++){
		int u = e[i].first;
		int v = e[i].second;

		if(u == n || v == n)
			ansr.push_back(min(u, v));
		else
			real_edges.push_back({u, v});
	}

	cout << cost << endl;

	cout << ansr.size() << endl;
	for(int i = 0; i < ansr.size(); i++)
		cout << ansr[i] + 1 << " \n"[i + 1 == ansr.size()];

	cout << real_edges.size() << endl;
	for(auto &el : real_edges)
		cout << el.first + 1 << " " << el.second + 1 << endl;

	return 0;
}