#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i,n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin() , v.end()
#define inputv(v,n) rep(i,n){\
    ll x;\
    cin>>x;\
    v.push_back(x);\
    }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, ans = 0, w, l;
priority_queue<ll> PQ;
vl gragh[200001];
set<PP> Gragh;
vector<PP> VP;
ll par[210000];//親の頂点
ll Size[210000];
ll root(ll x) {
	if (par[x] == x)return x;
	return par[x] = root(par[x]);
}
bool same(ll x, ll y) {
	return root(x) == root(y);
}
void unite(ll x, ll y) {
	if (same(x, y))return;
	Size[root(y)] += Size[root(x)];
	par[root(x)] = root(y);
}
void input() {
	cin >> n >> m;
	rep(i, m) {
		cin >> a >> b;
		gragh[a].push_back(b);
		gragh[b].push_back(a);
		Gragh.insert({ a,b });
		Gragh.insert({ b,a });
	}
}
void solve() {
	for (ll i = 1; i < n + 1; i++) {
		VP.push_back({ gragh[i].size(),i });
	}

	sort(all(VP));
	reverse(all(VP));

	for (int i = 1; i < n + 1; i++) {//初期化
		par[i] = i;
		Size[i] = 1;
	}

	for (ll i = 0; i < n; i++) {
		k = 0;
		x = VP[i].second;
		for (ll j = 1; j < n + 1; j++) {
			if (Gragh.count({ x,j }) != 1) {
				if (root(x) != root(j)) {
					k++;
					unite(x, j);
				}
			}
		}

		if (k == 0 && VP[i].first * 2 < n)break;
	}

	vl ANS;
	for (ll i = 1; i < n + 1; i++) {
		if (par[i] == i)ANS.push_back(Size[i]);
	}

	cout << ANS.size() - 1 << endl;

}

int main() {
	input();
	solve();
}