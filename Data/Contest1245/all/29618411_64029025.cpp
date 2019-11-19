#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2001;
constexpr int M = (N + 1) * N;

class UnionFind {
private:
	vector<int> p, size;
	int n;
public:
	UnionFind() {}

	UnionFind(int n) {
		// Initializing.
		size.assign(n + 1, 1);
		p.resize(n + 1);
		this->n = n;

		// Setting the representative of each set to be itself.
		for (int i = 1; i <= n; i++) {
			p[i] = i;
		}
	}

	/* Amortized O(1). */
	int find_set(int u) {
		if (u == p[u]) { // Found representative.
			return u;
		}

		// Compressing the path as we search for the set's representative.
		return p[u] = find_set(p[u]);
	}

	/* Amortized O(1). */
	void union_set(int u, int v) {
		// Finding representatives of u and v.
		int x = find_set(u);
		int y = find_set(v);

		// If u and v belong to different sets.
		if (x != y) {
			// Attaching the smaller tree to the bigger tree.
			if (size[x] < size[y]) {
				p[x] = y;
				size[y] += size[x];
			}
			else {
				p[y] = x;
				size[x] += size[y];
			}

			// Decreasing number of sets.
			n--;
		}
	}

	/* O(1). */
	int num_sets() {
		return n;
	}

	/* O(1). */
	int set_size(int u) {
		return size[find_set(u)];
	}
};

struct Edge{
	int u, v;
	long long w;

	bool operator < (const Edge &b) const {
		return w < b.w;
	}
};

vector<Edge> e;
vector<Edge> ans;
long long x[N + 1];
long long y[N + 1];
long long c[N + 1];
long long k[N + 1];
vector<int> power;
vector<Edge> connection;
int n; // (Input)

/* O(E * Log(E)). */
long long kruskal() {
	UnionFind uf;
	long long cost;

	// Creating a Union Find data structure with sets from 1 to n.
	uf = UnionFind(n);

	// Sorting edges according to their weights.
	sort(e.begin(), e.end());
	cost = 0;

	// For every edge (u, v).
	for (int i = 0; i < e.size(); i++) {
		// If vertex u and vertex v belongs to different sets.
		if (uf.find_set(e[i].u) != uf.find_set(e[i].v)) {
			// Edge (u, v) belongs to the Minimum Spanning Tree. Unite u's set with v's set.
			uf.union_set(e[i].u, e[i].v);
			ans.push_back(e[i]);
			cost += e[i].w;
		}
	}

	return cost;
}

long long dist(int u, int v) {
	return (abs(x[u] - x[v]) + abs(y[u] - y[v])) * (k[u] + k[v]);
}

int main() {
	int u, v, i;

	scanf("%d", &n);

	for (u = 1; u <= n; u++) {
		scanf("%lld%lld", x + u, y + u);
	}

	for (u = 1; u <= n; u++) {
		scanf("%lld", c + u);
	}

	for (u = 1; u <= n; u++) {
		scanf("%lld", k + u);
	}

	for (u = 1; u <= n; u++) {
		for (v = u + 1; v <= n; v++) {
			e.push_back({u, v, dist(u, v)});
		}

		e.push_back({u, n + 1, c[u]});
	}

	n++;
	printf("%lld\n", kruskal());
	n--;

	for (i = 0; i < ans.size(); i++) {
		if (ans[i].v == n + 1) {
			power.push_back(ans[i].u);
		}
		else {
			connection.push_back(ans[i]);
		}
	}

	printf("%d\n", (int)power.size());

	for (i = 0; i < power.size(); i++) {
		printf("%d ", power[i]);
	}

	printf("\n");

	printf("%d\n", (int)connection.size());

	for (i = 0; i < connection.size(); i++) {
		printf("%d %d\n", connection[i].u, connection[i].v);
	}

	return 0;
}
