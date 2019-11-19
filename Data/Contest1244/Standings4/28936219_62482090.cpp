#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<ll>> c(3);
	for(int i = 0; i < 3; ++i) {
		c[i] = vector<ll>(n);
		for (int j = 0; j < n; ++j) {
			cin >> c[i][j];
		}
	}

	vector<vector<int>> nei(n);

	for (int i = 0; i < n-1; ++i) {
		int u; int v;
		cin >> u >> v;
		--u;
		--v;

		nei[u].push_back(v);
		nei[v].push_back(u);
	}

	vector<int> indices(0);
	int next;
	for (int i = 0; i < n; ++i) {
		if (nei[i].size() == 1) {
			indices.push_back(i);
			next = nei[i][0];
			break;
		}
	}

	while (indices.size() < n) {
		auto neighbors = nei[next];
		if (neighbors.size() > 2) {
			cout << -1 << endl;
			return 0;
		} else if (neighbors.size() == 1) {
			indices.push_back(next);
			break;
		}
		int new_next = neighbors[0]==indices.back() ? neighbors[1] : neighbors[0];
		indices.push_back(next);
		next = new_next;
	}

	ll best_cost = 1e9 * 100001;
	vector<int> best_order = vector<int>{0,1,2};

	vector<vector<int>> options = vector<vector<int>>{{0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}};
	for (auto order : options) {
		ll cost = 0; 
		for (int i = 0; i < n; ++i) {
			cost += c[order[i%3]][indices[i]];
		}
		if (cost < best_cost) {
			best_cost = cost;
			best_order = order;
		}
	}
	cout << best_cost << endl;
	vector<int> colors(n);
	for (int i = 0; i < n; ++i) {
		colors[indices[i]] = best_order[i%3] + 1;
	}

	for (int i = 0; i < n; ++i) {
		cout << colors[i] << " ";
	}
	cout << endl;

	return 0;

}