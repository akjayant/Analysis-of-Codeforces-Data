#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x),end(x)
using ll = long long;

vector<vector<ll>> adj;

vector<array<ll, 3>> cost;

ll colors[3];

vector<ll> selColor;
ll color(ll n, ll c, ll p) {
	selColor[n] = colors[c % 3];
	for (ll nxt : adj[n]) {
		if (nxt != p) {
			return color(nxt, c + 1, n) + cost[n][selColor[n]];
		}
	}
	return cost[n][selColor[n]];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n;
	cin >> n;
	adj.resize(n);
	cost.resize(n);
	selColor.resize(n);
	
	for (ll t = 0; t < 3; t++) {
		for (ll i = 0 ; i < n; i++) {
			cin >> cost[i][t];
		}
	}
	
	for (ll i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	ll st = -1;
	for (ll i = 0; i < n; i++) {
		if (adj[i].size() == 1) {
			st = i;
		} else if (adj[i].size() > 2) {
			cout << "-1\n";
			return 0;
		}
	}
	
	vector<ll> ansC;
	ll ans = LLONG_MAX;
	for (colors[0] = 0; colors[0] < 3; colors[0]++) {
		for (colors[1] = 0; colors[1] < 3; colors[1]++) {
			for (colors[2] = 0; colors[2] < 3; colors[2]++) {
				if (colors[0] == colors[1] || colors[0] == colors[2] || colors[1] == colors[2])
					continue;
				
				ll cand = color(st, 0, -1);
				if (cand < ans) {
					ans = cand;
					ansC = selColor;
				}
			}
		}
	}
	
	cout << ans << "\n";
	for (ll c : ansC)
		cout << c + 1 << " ";
	cout << "\n";
}
