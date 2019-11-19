#include <bits/stdc++.h>
 
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
 
#define ll long long
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define x first
#define y second
 
using namespace std;
typedef vector <int> vi;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
inline void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
 
vector <pii> edges;
vector <pll> vec;
vector <int> usd;
vi pred;
vi solo;
 
const ll inf = 1LL * 100000000 * 10000000000;
 
int delta(int a, int b) {
	return (abs(vec[a].x-vec[b].x) + abs(vec[a].y-vec[b].y));
}
 
void dfs(int v) {
	usd[v] = 1;
	if(pred[v] == -1) {
		solo[v] = 1;
		return;
	}
 
	edges.pb({v, pred[v]});
 
	if(!usd[pred[v]]) {
		dfs(pred[v]);
	}
}
 
ll ans = 0;
 
void solve() {
	int n;
	cin >> n;
	solo.assign(n, 0);
	pred.assign(n, -1);
	usd.assign(n, 0);
	vec.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> vec[i].x >> vec[i].y;
	}
	/*vi c(n);
	for(int i = 0; i < n; ++i) cin >> c[i];*/
	vector <pair<ll, int>> c(n, {0,-1});
	for(int i = 0; i < n; ++i) cin >> c[i].x;
	vector <ll> k(n);
	for(int i = 0; i < n; ++i) cin >> k[i];
 
	for(int num = 0; num < n; ++num) {
		int minimal_edge = -1;
		for(int i = 0; i < n; ++i) {
			if(!usd[i]) {
				if(minimal_edge == -1) {
					minimal_edge = i;
					continue;
				}
			}
			if(!usd[i] && c[i].x < c[minimal_edge].x) {
				minimal_edge = i;
			}
		}
		// cout << "+= " << c[minimal_edge].x << "\n";
		// cout << "minimal = " << minimal_edge << "\n";
		ans += c[minimal_edge].x;
		usd[minimal_edge] = 1;
		pred[minimal_edge] = c[minimal_edge].y;
		for(int i = 0; i < n; ++i) {
			if(!usd[i]) {
				c[i] = min( c[i], { (k[i] + k[minimal_edge]) * delta(minimal_edge, i) , minimal_edge} );
			}
		}
	}
	cout << ans << "\n";
	// for(auto i : pred) cout << i << " "; cout << "\n";
	usd.assign(n, 0);
	for(int i = 0; i < n; ++i) {
		if(!usd[i]) dfs(i);
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i) if(solo[i]) cnt++;
	cout << cnt << "\n";
	for(int i = 0; i < n; ++i) if(solo[i]) cout << i + 1 << " "; cout << "\n";
 
	cout << edges.size() << "\n";
	for(int i = 0; i < edges.size(); ++i) {
		cout << edges[i].x + 1 << " " << edges[i].y + 1 << "\n";
	}
}
 
// #define lolipop
 
signed main() {
#ifdef lolipop
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
 
	fastio();
	solve();
 
}