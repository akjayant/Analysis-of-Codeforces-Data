#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(NULL);

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

const int INT_INF = 1e9;
const ll LL_INF = 1e18;
const int MAXN = 2010;

typedef struct GE {
	int to;
	ll w;
}GE;
int n;
ll C[MAXN], K[MAXN];
bool chk[MAXN];

int p[10002], gr[10002], gs[10002];
int findp(int x) {
	if (p[x] == x) return x;
	return p[x] = findp(p[x]);
}

void link(int x, int y) {
	x = findp(x); y = findp(y);
	if (x == y) return;
	if (gr[x] > gr[y]) swap(x, y);
	p[x] = y;
	gs[y] += gs[x];
	if (gr[x] == gr[y]) gr[y]++;
}

typedef struct V {
	int x, y;
}V;
V cow[MAXN];

typedef struct E {
	int u, v;
	ll c;
}E;

vector<E> es;
int main() {
	scanf("%d", &n);
	p[n] = n;

	for (int i = 0; i < n; i++) {
		p[i] = i;

		int x, y;
		scanf("%d %d", &x, &y);
		cow[i] = { x, y };
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &C[i]);
		es.push_back({ i, n, C[i] });
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &K[i]);
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			es.push_back({ i, j, (K[i] + K[j])*(abs(cow[i].x - cow[j].x) + abs(cow[i].y - cow[j].y)) });
		}
	}
	sort(es.begin(), es.end(), [](E e1, E e2) {
		return e1.c < e2.c;
	});


	vector<int> vs;
	vector<pii> vvs;
	for (int i = 0; i < es.size(); i++) {
		int pu = findp(es[i].u);
		int pv = findp(es[i].v);
		if (pu == pv) continue;
		if (es[i].v == n) {
			vs.push_back(es[i].u);
		}
		else {
			vvs.push_back({ es[i].u, es[i].v });
		}
		link(pu, pv);
		ans += es[i].c;
	}
	printf("%lld\n", ans);

	printf("%d\n", vs.size());
	sort(vs.begin(), vs.end());
	for (auto v : vs)
		printf("%d ", v + 1);
	puts("");

	printf("%d\n", vvs.size());
	for (auto ce : vvs)
		printf("%d %d\n", ce.first + 1, ce.second + 1);
	return 0;
}