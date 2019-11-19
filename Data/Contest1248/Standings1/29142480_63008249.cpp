#include <bits/stdc++.h>
#define rep(i, a, b) for(int i(a), i##_ORZ(b); i <= i##_ORZ; i++)
#define drep(i, a, b) for(int i(a), i##_ORZ(b); i >= i##_ORZ; i--)
using namespace std;
const int maxn = 4000010;
int n, m, head[maxn], ver[maxn], Next[maxn], tot;
int dfn[maxn], low[maxn], num, scc, bel[maxn], ins[maxn], top, sta[maxn];
void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void tarjan(int x) {
	dfn[x] = low[x] = ++num;
	sta[++top] = x; ins[x] = 1;
	for(int i = head[x]; i; i = Next[i]) 
		if(!dfn[ver[i]]) tarjan(ver[i]), low[x] = min(low[x], low[ver[i]]);
		else if(ins[ver[i]]) low[x] = min(low[x], dfn[ver[i]]);
	if(dfn[x] == low[x]) {
		scc++; int z = 0;
		while(z != x) {
			z = sta[top--], ins[z] = 0, bel[z] = scc;
		}
	}
}
void clear() {
	rep(i, 1, n) head[i] = dfn[i] = low[i] = bel[i] = ins[i] = 0;
	top = num = scc = tot = 0;
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y);
		}
		rep(i, 1, n) if(!dfn[i]) tarjan(i);
		if(scc == 1) printf("No\n");
		else {
			printf("Yes\n");
			int cnt = 0;
			rep(i, 1, n) if(bel[i] == 1) cnt++;
			printf("%d %d\n", cnt, n - cnt);
			rep(i, 1, n) if(bel[i] == 1) printf("%d ", i); 
			printf("\n");
			rep(i, 1, n) if(bel[i] != 1) printf("%d ", i);
			printf("\n");
		}
		clear();
	}
	return 0;
}
