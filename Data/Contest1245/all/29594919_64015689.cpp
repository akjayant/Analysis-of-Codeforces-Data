#include<bits/stdc++.h>

using namespace std;
#define endl '\n'

typedef pair<int, int> pii;
typedef long long ll;

struct DS{

	vector<int> par;
	vector<int> size;

	int n;

	void init(int _n){

		n = _n;
		par.resize(n + 1);
		size.resize(n + 1, 1);

		for(int i = 0; i <= n; i++){
			par[i] = i;
		}
	}

	int get_id(int u){
		if(par[u] == u){
			return u;
		}
		return get_id(par[u]);
	}	

	bool join(int u, int v){
		u = get_id(u);
		v = get_id(v);

		if(u == v){
			return false;
		}

		if(size[u] < size[v]){
			par[u] = v;
			size[v] += size[u];
		}else{
			par[v] = u;
			size[u] += size[v];
		}
		return true;
	}

	int get_size(int u){
		u = get_id(u);
		return size[u];
	}
};

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n;
	cin >> n;
	vector<pii> s(n);
	for(int i = 0; i < n; i++){
		int u , v;
		cin >> u >> v;
		s[i] = {u , v};
	}
	vector<int> c(n);
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	vector<int> k(n);
	for(int i = 0; i < n; i++){
		cin >> k[i];
	}

	vector<pair<long long, pair<int, int>>> e;

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			ll dist = abs(s[i].first - s[j].first) + abs(s[i].second - s[j].second);
			e.push_back({1LL * (k[i] + k[j]) * dist , {i , j}});
		}
	}	

	for(int i = 0; i < n; i++){
		e.push_back({c[i], {i , n}});
	}

	DS ds;ds.init(n + 1);
	sort(e.begin(), e.end());
	ll ans = 0;
	vector<int> conn;
	vector<pair<int, int>> linked;
	for(auto ppp : e){
		int w = ppp.first;
		int u = ppp.second.first;
		int v = ppp.second.second;

		if(ds.join(u , v)){
			ans += w;
			if(u > v){
				swap(u , v);
			}
			if(v == n){
				conn.push_back(u + 1);
			}
			else{
				linked.push_back({u + 1, v + 1});
			}
		}
	}

	cout << ans << endl;
	cout << conn.size() << endl;
	for(auto v : conn){
		cout << v << " ";
	}
	cout << endl;

	cout << linked.size() << endl;
	for(auto v : linked){
		cout << v.first << " " << v.second << endl;;
	}

	return 0;
}

