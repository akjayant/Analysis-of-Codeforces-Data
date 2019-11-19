#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <cmath>
#include <tuple>
using namespace std;
#define fio ios::sync_with_stdio(0),cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M, K, T;

struct Point {
	int x, y;
} inp[2005];

ll c[2005], k[2005];

ll dist(Point a, Point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

struct Edge {
	int a, b; ll c;
	bool used;
	bool operator<(const Edge &o) const {
		return c < o.c;
	}
};

int p[2005];

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return 0;
	p[a] = b;
	return 1;
}

vector<Edge> v;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x, y; scanf("%d %d", &x, &y);
		inp[i] = {x, y};
		p[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		scanf("%lld", c + i);
		v.push_back({0, i, c[i]});
	}
	for (int i = 1; i <= N; i++) {
		scanf("%lld", k + i);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			v.push_back({i, j, (k[i] + k[j]) * dist(inp[i], inp[j]), 0});
		}
	}
	vector<int> install;
	vector<pii> edges;
	sort(v.begin(), v.end());
	ll ret = 0;
	for (auto &[a, b, c, used] : v) {
		if (merge(a, b)) {
			ret += c;
			if (a == 0) install.push_back(b);
			else {
				edges.push_back({a, b});
			}
		}
	}
	sort(install.begin(), install.end());
	printf("%lld\n", ret);
	printf("%d\n", install.size());
	for (int x : install) {
		printf("%d ", x);
	}
	puts("");
	printf("%d\n", edges.size());
	for (auto [a, b] : edges) {
		printf("%d %d\n", a, b);
	}
	
}