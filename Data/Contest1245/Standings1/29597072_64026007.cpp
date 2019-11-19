#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <vector>

#define FOR(i, n) for(int i = 0; i < n; i++) 

#define pow CHANGETHENAMESTUPID

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MAXN = 2010;

int n;
int x[MAXN], y[MAXN];
int c[MAXN], k[MAXN];

void load() {
	scanf("%d", &n);
	FOR(i, n) scanf("%d%d", x + i, y + i);
	FOR(i, n) scanf("%d", c + i);
	FOR(i, n) scanf("%d", k + i);
}

int par[MAXN];
ll cost[MAXN];
int minPower[MAXN];

int parent(int x) {
	return par[x] < 0 ? x : par[x] = parent(par[x]);
}

bool mbJoin(int x, int y, ll weight) {
	x = parent(x);
	y = parent(y);
	if (x == y) return false;
	if (par[x] > par[y]) swap(x, y);
	int newMinPower = min(minPower[x], minPower[y]);
	ll newCost = cost[x] - minPower[x] + cost[y] - minPower[y] + newMinPower + weight;
	if (cost[x] + cost[y] > newCost) {
		par[x] += par[y];
		par[y] = x;
		cost[x] = newCost;
		minPower[x] = newMinPower;
		return true;
	}
	return false;
}

void solve() {
	vector<pair<ll, pii>> edges;
	FOR(i, n) for (int j = i + 1; j < n; j++) {
		ll weight = abs(x[i] - x[j]) + abs(y[i] - y[j]);
		weight *= k[i] + k[j];
		edges.push_back({weight, {i, j}});
	}
	FOR(i, n) {
		par[i] = -1;
		cost[i] = minPower[i] = c[i];
	}
	vector<pii> cons;
	sort(edges.begin(), edges.end());
	for (auto edge : edges) {
		if (mbJoin(edge.second.first, edge.second.second, edge.first)) 
			cons.push_back(edge.second);
	}
	ll sol = 0;
	vector<int> powers; 
	FOR(i, n) {
		if (par[i] < 0) {
			sol += cost[i];
			FOR(j, n) {
				if (parent(j) == i && c[j] == minPower[i]) {
					powers.push_back(j);
					break;
				}
			}
		}
	}
	printf("%lld\n", sol);
	printf("%d\n", (int) powers.size());
	for (int x : powers) printf("%d ", x + 1); printf("\n");
	printf("%d\n", (int) cons.size());
	for (pii par : cons) printf("%d %d\n", par.first + 1, par.second + 1);
}

int main() {
	load();
	solve();
	return 0;
}
