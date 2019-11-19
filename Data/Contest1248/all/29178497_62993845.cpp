// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl;
#define fastIO std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);

typedef long long ll;
typedef long double ld;

std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());

const double PI = atan2(0., -1.);
const int INF = 0x3f3f3f3f;
const int N = 1000100;

std::vector<int> g[N], gr[N];
bool used[N];
int cmp[N];
std::vector<int> cmps[N];
std::vector<int> order;
int curCmp = 0;
bool isBad[N];

void topSort(int v) {
	used[v] = true;

	for (auto to : g[v]) {
		if (!used[to]) {
			topSort(to);
		}
	}

	order.push_back(v);
}

void dfs(int v) {
	used[v] = true;
	cmp[v] = curCmp;
	cmps[curCmp].push_back(v);

	for (auto to : gr[v]) {
		if (!used[to]) {
			dfs(to);
		}
	}
}

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i) {
		g[i].clear();
		gr[i].clear();
		cmps[i].clear();
		used[i] = false;
		cmp[i] = 0;
		isBad[i] = false;
	}

	curCmp = 0;
	order.clear();

	while (m--) {
		int from, to;
		scanf("%d%d", &from, &to);

		g[from - 1].push_back(to - 1);
		gr[to - 1].push_back(from - 1);
	}

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			topSort(i);
		}
	}

	for (int i = 0; i < n; ++i) {
		used[i] = false;
	}

	std::reverse(order.begin(), order.end());

	for (auto i : order) {
		if (!used[i]) {
			dfs(i);
			++curCmp;
		}
	}

	if (curCmp == 1) {
		printf("No\n");
		return;
	}

	printf("Yes\n");

	for (int i = 0; i < n; ++i) {
		for (auto to : g[i]) {
			if (cmp[to] != cmp[i]) {
				isBad[cmp[i]] = true;
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < curCmp; ++i) {
		if (isBad[i]) {
			continue;
		}

		for (int j = 0; j < n; ++j) {
			used[j] = false;
		}

		printf("%d %d\n", (int)cmps[i].size(), n - (int)cmps[i].size());

		for (auto i : cmps[i]) {
			printf("%d ", i + 1);
			used[i] = true;
		}
		printf("\n");

		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				printf("%d ", i + 1);
			}
		}
		printf("\n");

		return;
	}
}

int main(void) {
	int t;
	scanf("%d", &t);

	while (t--) {
		solve();
	}

	return 0;
}
