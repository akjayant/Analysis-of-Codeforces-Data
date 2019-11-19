#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 100005;

int n, m;
int fa[N], vis[N];
vector<int> g[N], ans;

int Sk(int x) {
	return fa[x] == x ? x : fa[x] = Sk(fa[x]);
}

void Bfs(int s) {
	static queue<int> Q;
	Q.push(s), fa[s] = Sk(s + 1);
	ans.push_back(1);
	for (int x; !Q.empty(); ) {
		x = Q.front(), Q.pop();
		for (int v : g[x]) vis[v] = x;
		for (int i = Sk(1); i <= n; i = Sk(i + 1)) {
			if (vis[i] != x) fa[i] = Sk(i + 1), Q.push(i), ++ans.back();
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) fa[i] = i;
	fa[n + 1] = n + 1;
	for (int i = 1; i <= n; i = Sk(i + 1)) Bfs(i);
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size() - 1);
	//for (int i : ans) printf("%d ", i);
	//putchar('\n');

	return 0;
}
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <algorithm>
//#include <map>
//#define mp make_pair
//#define ll long long
//using namespace std;
//ll n, t, k, m, ans = 0;
//vector<int> G[100010];
//int parent[100010];
//int main() {
//	ios::sync_with_stdio(false); 
//	cin.tie(nullptr); 
//	cout.tie(nullptr);
//	cin >> n >> m;
//	for (int i = 1; i <= n; ++i) parent[i] = i;
//	for (int i = 1; i <= m; ++i) {
//		int x, y; cin >> x >> y;
//		G[x].push_back(y);
//		G[y].push_back(x);
//	}
//	for (int i = 1; i <= n; ++i) {
//
//	}
//}
