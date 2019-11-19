
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>
#include <sstream>
#include <map>
#include <math.h>
#include <stdio.h>
#include <stack>
#include <set>

using  namespace std;
#define ll long long


int main() {
	ll n;
	cin >> n;
	vector<ll> x(n), y(n), c(n), k(n);
	for (ll i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (ll i = 0; i < n; i++) cin >> c[i];
	for (ll i = 0; i < n; i++) cin >> k[i];
	vector < pair < ll, pair<ll, ll> > > g;
	for (ll i = 0; i < n; i++) {
		for (ll j = i ; j < n; j++) {
			ll cost = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
			g.push_back( { cost, { i,j } });
		
			g.push_back({ cost,{j,i} });
		}
	}
	for (ll i = 0; i < n; i++) {
		g.push_back({ c[i],{i,n} });
		g.push_back({ c[i],{n,i} });
	}
	ll m = g.size();


	ll cost = 0;
	vector < pair<int, int> > res;
	n++;
	sort(g.begin(), g.end());
	vector<int> tree_id(n);
	for (ll i = 0; i < n; ++i)
		tree_id[i] = i;
	for (ll i = 0; i < m; ++i)
	{
		ll a = g[i].second.first, b = g[i].second.second, l = g[i].first;
		if (tree_id[a] != tree_id[b])
		{
			cost += l;
			res.push_back(make_pair(a, b));
			ll old_id = tree_id[b], new_id = tree_id[a];
			for (ll j = 0; j < n; ++j)
				if (tree_id[j] == old_id)
					tree_id[j] = new_id;
		}
	}
	cout << cost << '\n';
	vector<int> ans1;
	vector<pair<int, int>> ans2;
	for (auto p : res) {
		if (p.first == n-1) ans1.push_back(p.second);
		if (p.second == n-1) ans1.push_back(p.first);
		if (p.second != n-1 && p.first != n-1) {
			ans2.push_back(p);
		}
	}
	cout << ans1.size() << '\n';
	for (int i = 0; i < ans1.size(); i++) cout << ans1[i]+1 << ' ';

	cout << '\n' << ans2.size() << '\n';
	for (auto p : ans2) cout << p.first+1 << ' ' << p.second+1 << '\n';

}