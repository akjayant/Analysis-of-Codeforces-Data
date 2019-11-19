#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cassert>
using namespace std;

typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
constexpr int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
long long c[maxn], k[maxn];
long long x[maxn], y[maxn];
struct Edge {
	int x, y;
	long long cost;
	Edge(int x = 0, int y = 0, long long cost = 0) :x(x), y(y), cost(cost) { }
};
long long dis(int a, int b) {
	return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}
int pre[maxn];
int find(int x) {
	if (pre[x] == x) return x;
	else return pre[x] = find(pre[x]);
}
void add(int u, int v) {
	int uu = find(u);
	int vv = find(v);
	if (uu > vv) swap(uu, vv);
	pre[uu] = vv;
}
bool build[maxn];
int main() {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		pre[i] = i;
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &k[i]);
	vector<Edge>edge;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			long long cost = (k[i] + k[j]) * dis(i, j);
			edge.push_back(Edge(i, j, cost));
		}
		edge.push_back(Edge(0, i, c[i]));
	}
	sort(edge.begin(), edge.end(), [](const Edge& a, const Edge& b)->bool {return a.cost < b.cost; });
	vector<int>build;
	vector<Edge>connect;
	long long ans = 0;
	int cnt = 0;
	for (auto e : edge) {
		int xx = find(e.x);
		int yy = find(e.y);
		if (xx != yy) {
			add(xx, yy);
			ans += e.cost;
			if (e.x == 0 || e.y == 0) {
				build.push_back(max(e.x, e.y));

			}
			else {
				connect.push_back(e);
			}
		}
		
	}
	sort(build.begin(), build.end());
	
	printf("%lld\n", ans);
	printf("%d\n", build.size());
	for (int i = 0; i < build.size(); i++) {
		printf("%d%c", build[i], " \n"[i == build.size() - 1]);
	}
	printf("%d\n", connect.size());
	for (auto p : connect) {
		printf("%d %d\n", p.x, p.y);
	}
	return 0;
}