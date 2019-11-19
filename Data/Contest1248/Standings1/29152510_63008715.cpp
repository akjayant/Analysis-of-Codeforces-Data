#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define test cerr << '!' << endl;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main0 ();
int main () {
	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\98497\\Desktop\\code\\file.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	// clock_t start,end;
	// start = clock();
	main0();
	// end = clock();
	// cout << (end - start) << endl;
	#ifndef ONLINE_JUDGE
		fclose(stdin);
	#endif
	return 0;
}

const int INF = 0x3f3f3f3f;
const int N = 1e6 + 5;
const int M = 1e5;
const int mod = 1e9 + 7;

vector <int> e[N];
int dfn[N], low[N];
int col[N], vis[N], cnt[N], deg[N];
int n, m;
int flag, deep;

stack <int> stk;
void tarjan (int u) {
	dfn[u] = low[u] = ++deep;
	vis[u] = 1;
	stk.push(u);
	for (int i = 0;i < e[u].size();i++) {
		int v = e[u][i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else {
			 if (vis[v])
				 low[u] = min(low[u], low[v]);
		}
	}
	
	if (dfn[u] == low[u]) {
		col[0]++;
		while (true) {
			int t = stk.top(); stk.pop();
			col[t] = col[0];
			vis[t] = 0;
			if (t == u) break;
		}
	}
}

int main0 () {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		deep = 0;
		flag = 0;
		//col[0] = 0;
		for (int i = 0;i <= n;i++) {
			e[i].clear();
			dfn[i] = 0;
			low[i] = 0;
			vis[i] = 0;
			col[i] = 0;
			cnt[i] = deg[i] = 0;
		}
		for (int i = 1;i <= m;i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			if (u == v) continue;
			e[u].pb(v);
		}
		
		for (int i = 1;i <= n;i++) {
			if (!dfn[i]) tarjan(i);
		}
		
		for (int i = 1;i <= n;i++) {
			//cout << i << ':' << col[i] << endl;
			cnt[col[i]]++;
		}
		
		for (int i = 1;i <= n;i++) {
			for (int j = 0;j < e[i].size();j++) {
				int v = e[i][j];
				if (col[i] != col[v]) deg[col[i]]++;
			}
		}
		
		for (int i = 1;i <= n;i++) {
			if ((!deg[col[i]]) && (cnt[col[i]] < n)) {
				flag = col[i];
				break;
			}
		}
		
		if (flag) {
			printf("YES\n");
			printf("%d %d\n", cnt[flag], n - cnt[flag]);
			for (int i = 1;i <= n;i++) {
				if (col[i] == flag) printf("%d ", i);
			} puts("");
			for (int i = 1;i <= n;i++) {
				if (col[i] != flag) printf("%d ", i);
			} puts("");
		} else {
			printf("NO\n");
		}
	}
}
