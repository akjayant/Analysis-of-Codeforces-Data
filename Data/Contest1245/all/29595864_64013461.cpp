#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using ull = unsigned long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vs = vector<string>;
using vvs = vector<vs>;
using vc = vector<char>;
using vvc = vector<vc>;
using ii = pair<int,int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vvdd = vector<vdd>;
using Mii = map<int,int>;
using vMii = vector<Mii>;
using Si = set<int>;
using vSi = vector<Si>;
using vvSi = vector<vSi>;

#define fi first
#define se second
#define INF 1e9 + 5
#define mod(a,m) (a%m+m)%m
#define PB push_back
#define MP make_pair

struct Edge {
	int from, to;
	ll weight;
	
	bool operator<(const Edge& a) {
		return weight < a.weight;
	}
};

vi repr;
vi rang;

int clique(int a) {
	if(repr[a] == a) return a;
	return repr[a] = clique(repr[a]);
}

void unite(int a, int b) {
	if(rang[a] < rang[b]) swap(a, b);
	repr[b] = a;
	if(rang[a] == rang[b]) rang[a]++;
}

vii v;

ll mdist(int i, int j) {
	return ll(abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second));
}

int main(){
//	cout.setf(ios::fixed);
//	cout.precision(4);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin >> n) {
		v = vii(n);
		vector<Edge> G;
		for (int i = 0; i < n; ++i) {
			cin >> v[i].first >> v[i].second;
		}
		for (int i = 0; i < n; ++i) {
			int c;
			cin >> c;
			G.push_back({0, i+1, c});
		}
		vll k(n);
		for (int i = 0; i < n; ++i) {
			cin >> k[i];
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				ll cost = (k[i] + k[j]) * mdist(i, j);
				G.push_back({i+1, j+1, cost});
			}
		}
		
		vi so;
		vii pa;
		
		sort(G.begin(), G.end());
		repr = vi(n+1);
		for (int i = 0; i <= n; ++i) repr[i] = i;
		rang = vi(n+1, 1);
		ll ans = 0;
		for (int i = 0; i < G.size(); ++i) {
			int a = clique(G[i].from);
			int b = clique(G[i].to); 
			if(a != b) {
				unite(a, b);
				ans += G[i].weight;
				if(G[i].from == 0 or G[i].to == 0) so.push_back(G[i].from + G[i].to);
				else {
					pa.push_back({G[i].from, G[i].to});
				}
			}
		}
		cout << ans << endl;
		cout << so.size() << endl;
		for (int i = 0; i < so.size(); ++i) {
			cout << so[i] << " ";
		}
		cout << endl << pa.size() << endl;
		for (ii x : pa) cout << x.first << " " << x.second << endl;
	}
}


