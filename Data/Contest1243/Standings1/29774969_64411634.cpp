#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define v vector
#define ALL(x) x.begin(),x.end()
#define rALL(x) x.rbegin(),x.rend()
#define mp make_pair
#define fi first
#define se second
#define endl '\n'

const ll mod = 1e9 + 7;
const ld PI = acos(-1.0);

template<typename T> struct DSU {
	vector<T> parent;
	vector<T> size;
	T numComponents = 0;
	DSU(T n = 0) {
		if(n >= 0)
			init(n);
	}
	void init(T n = 0) {
		parent.resize(n);
		size.assign(n, 1);
		numComponents = n;
		for (T i = 0; i < n; i++)
			parent[i] = i;
	}
	T getParent(T x) {
		return (x == parent[x]) ? x : parent[x] = getParent(parent[x]);
	}
	bool merge(T x, T y) {
		x = getParent(x);
		y = getParent(y);
		if (x == y) {
			return false;
		} 
		if (size[x] < size[y]) {
			swap(x, y);
		}
		parent[y] = x;
		size[x] += size[y];
		numComponents--;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, m;
	cin >> n >> m;
	v<v<ll>> g(n);
	map<ll, ll> toCompute;
	ll ans = 0;
	for(ll i = 0; i < n; i ++) {
		toCompute[i] = 0;
	}
	for(ll i = 0; i < m; i ++) {
		ll a, b;
		cin >> a >> b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}
	DSU<ll> uf(n);
	for(ll i = 0; i < n; i ++) {
		map<ll, ll> toMerge;
		for(auto j : g[i]) {
			if(toCompute.count(uf.getParent(j))) {
				toCompute[uf.getParent(j)] ++;
			}
		}
		ll toPut = i;
		for(auto j : toCompute) {
			if(j.second < uf.size[j.first]) {
				uf.merge(toPut, j.first);
				toPut = uf.getParent(toPut);
			}
			else toMerge[j.first] = 0;
		}
		toCompute = toMerge;
		toCompute[toPut] = 0;
	}
	cout << uf.numComponents - 1 << endl;
	return 0;
}