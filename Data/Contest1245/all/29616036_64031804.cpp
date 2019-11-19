#include <cstdio>

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 2000 + 5;
int x[maxn], y[maxn];
long long c[maxn];
long long k[maxn];

struct edge {
	int u, v;
	long long w;
	edge(int _u, int _v, long long _w) : u(_u), v(_v), w(_w) {}
	bool operator < (const edge& rhs) const {
		return w < rhs.w;
	}
};

vector<edge> es;
bool vis[maxn];

int par[maxn];


int Find(int x) {
	if (x == par[x]) return x;
	return par[x] = Find(par[x]);
}

long long dis(int i, int j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main(void) {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &k[i]);
	}

	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}


	for (int i = 1; i <= n; i++) {
		es.emplace_back(0, i, c[i]);
		for (int j = i + 1; j <= n; j++) {
			es.emplace_back(i, j, dis(i, j) * (k[i] + k[j]));
		}
	}


	sort(es.begin(), es.end());

	long long res = 0;
	vector<int> res1;
	vector<pair<int, int>> res2;
	for (const edge& e : es) {
		int u = e.u;
		int v = e.v;
		long long w = e.w;
		int fu = Find(u);
		int fv = Find(v);
		if (fu != fv) {
			par[fv] = fu;
			res += w;
			if (u == 0 || v == 0) {
				if (u == 0) res1.push_back(v);
				else res1.push_back(u);
			} else {
				res2.emplace_back(u, v);
			}
		}
	}
	printf("%lld\n", res);
	printf("%d\n", res1.size());
	for (int x : res1) printf("%d ", x);
	printf("\n%d\n", res2.size());
	for (const auto& p : res2) printf("%d %d\n", p.first, p.second);
	return 0;
}