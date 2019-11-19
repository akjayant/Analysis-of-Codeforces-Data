#include <iostream>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct ds {
	vector<int> parent;
	vector<int> rnk;

	ds(int n) {
		rnk = vector<int>(n, 0);
		parent = vector<int>(n);
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}

	int find(int u) {
		if (u!=parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	void un(int x, int y) {
		if (x!=y) {
			if (rnk[x] < rnk[y]) {
				rnk[y] += rnk[x];
				parent[x] = y;
			} else {
				rnk[x] += rnk[y];
				parent[y] = x;
			}
		}
	}
};

int main()
{

	int n;
	cin >> n;

	vector<int> x(n);
	vector<int> y(n);

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	vector<ll> c(n);

	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	vector<ll> k(n);

	for (int i = 0; i < n; ++i) {
		cin >> k[i];
	}
	// weight, u, v
	vector<pair<ll,pair<int,int>>> edges;

	for (int i = 0; i < n; ++i) {
		edges.push_back(make_pair(c[i], make_pair(i, n)));
		for (int j = i+1; j < n; ++j) {
			edges.push_back(make_pair((k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])), make_pair(i, j)));
		}
	}

	sort(edges.begin(), edges.end());


	vector<pair<int, int>> final;
	vector<int> central;

	ll cost = 0;

	ds ds(n+1);

	for (auto & edge : edges) {
		int u = edge.second.first;
		int v = edge.second.second;

		int fu = ds.find(u);
		int fv = ds.find(v);

		if (fu!=fv) {
			ds.un(fu, fv);
			ll w = edge.first;
			cost += w;
			if (v==n)
				central.push_back(u);
			else
				final.push_back(make_pair(u,v));
		}
	}

	cout << cost << "\n";
	cout << central.size() << "\n";
	for (auto ce : central) {
		cout << ce+1 << " ";
	}
	cout << "\n";

	cout << final.size() << "\n";
	for (auto con : final) {
		cout << con.first+1 << " " << con.second+1 << "\n";
	}
}