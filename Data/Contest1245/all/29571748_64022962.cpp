#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

mt19937 gen((uint) chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2100;

const int INF = 1'000'000'000;
const ll LLINF = 4LL * INF * INF;

ll x[N];
ll y[N];
ll g[N][N];
ll dist[N];
ll placeCost[N];
ll lenCost[N];
int p[N];
char used[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	fill(dist, dist + n + 1, LLINF);
	fill(p, p + n + 1, -1);

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> placeCost[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> lenCost[i];
		g[n][i] = g[i][n] = placeCost[i];

		for (int j = 0; j < i; j++) {
			ll d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			g[i][j] = g[j][i] = d * (lenCost[i] + lenCost[j]);
		}
	}

	ll res = 0;
	dist[n] = 0;

	vector<int> place;
	vector<pair<int, int>> edges;

	for (int i = 0; i <= n; i++) {
		int v = -1;

		for (int j = 0; j <= n; j++) {
			if (!used[j] && (v == -1 || dist[j] < dist[v])) {
				v = j;
			}
		}

		assert(v != -1);
		used[v] = 1;

		if (p[v] != -1) {
			res += g[p[v]][v];

			if (p[v] == n) {
				place.push_back(v + 1);
				assert(v != n);
			} else {
				edges.push_back({v + 1, p[v] + 1});
				assert(v != n && p[v] != n);
			}
		}

		for (int j = 0; j <= n; j++) {
			if (g[v][j] < dist[j]) {
				dist[j] = g[v][j];
				p[j] = v;
			}
		}
	}

	cout << res << "\n";
	cout << place.size() << "\n";

	for (int id : place) {
		cout << id << "\n";
	}

	cout << edges.size() << "\n";

	for (auto p : edges) {
		cout << p.first << " " << p.second << "\n";
	}

	return 0;
}