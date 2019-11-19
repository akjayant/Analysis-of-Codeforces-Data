#include<bits/stdc++.h>
#define f first
#define s second

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> xy(n);
	vector<long long> c(n);
	vector<long long> k(n);
	for (int i = 0; i < n; i++) {
		cin >> xy[i].f >> xy[i].s;
	}
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < n; i++) cin >> k[i];
	int mincost = INT_MAX;
	int ind = -1;
	for (int i = 0; i < n; i++) {
		if (c[i] < mincost) {
			mincost = c[i];
			ind = i;
		}
	}
	vector<pair<long long, int>> dist(n);
	for (int i = 0; i < n; i++) {
		dist[i].f = c[i];
		dist[i].s = -1;
	}
	for (int j = 0; j < n; j++) {
		if (j == ind) continue;
		long long curcost = abs(xy[ind].f - xy[j].f) + abs(xy[ind].s - xy[j].s);
		curcost *= (k[j] + k[ind]);
		if (dist[j].f > curcost) {
			dist[j].f = curcost;
			dist[j].s = ind;
		}
	}
	vector<bool> used(n);
	used[ind] = true;
	long long totalcost = c[ind];
	vector<pair<int, int>> edges;
	vector<int> verts = {ind};
	for (int i = 0; i < n - 1; i++) {
		int curind = 0;
		long long curmin = 1e18;
		for (int j = 0; j < n; j++) {
			if (used[j]) continue;
			if (dist[j].f < curmin) {
				curmin = dist[j].f;
				curind = j;
			}
		}
		used[curind] = true;
		totalcost += dist[curind].f;
		if (dist[curind].s == -1) {
			verts.push_back(curind);
		} else {
			edges.push_back({curind, dist[curind].s});
		}
		for (int j = 0; j < n; j++) {
			if (used[j]) continue;
			long long curcost = abs(xy[curind].f - xy[j].f) + abs(xy[curind].s - xy[j].s);
			curcost *= (k[curind] + k[j]);
			if (dist[j].f > curcost) {
				dist[j].f = curcost;
				dist[j].s = curind; 
			}
		}
	}
	cout << totalcost << endl;
	cout << verts.size() << endl;
	for (int i = 0; i < verts.size(); i++) cout << verts[i] + 1 << ' ';
	cout << endl << edges.size() << endl;
	for (int i = 0; i < edges.size(); i++) {
		cout << edges[i].f + 1 << ' ' << edges[i].s + 1 << "\n";
	}
}

int main() {
	solve();
	return 0;
}