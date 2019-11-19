#include <bits/stdc++.h>
#define rep(i, a, b) for(int i(a), i##_ORZ(b); i <= i##_ORZ; i++)
#define drep(i, a, b) for(int i(a), i##_ORZ(b); i >= i##_ORZ; i--)
using namespace std;
typedef long long ll;
const int maxn = 100010;
const ll inf = 1e18;
int n, c[5][maxn], head[maxn], ver[maxn * 2], Next[maxn * 2], tot;
int deg[maxn], col[maxn], fc[maxn];
ll f[maxn][2][2];
void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
	deg[x]++;
}
ll dfs(int x, int pa, int a1, int a2) {
	col[x] = a1;
	for(int i = head[x]; i; i = Next[i]) if(ver[i] != pa) {
		rep(t, 1, 3) if(t != a1 && t != a2) 
			return dfs(ver[i], x, t, a1) + c[a1][x];
	}
	//cout << x << ' ' << a1 << ' ' << res + c[a1][x] << endl;
	return c[a1][x];
}
int main() {
	scanf("%d", &n);
	int x, y;
	rep(i, 1, n) scanf("%d", &c[1][i]);
	rep(i, 1, n) scanf("%d", &c[2][i]);
	rep(i, 1, n) scanf("%d", &c[3][i]);
	rep(i, 1, n - 1) scanf("%d%d", &x, &y), add(x, y), add(y, x);
	rep(i, 1, n) if(deg[i] > 2) { printf("-1\n"); return 0; }
	int rt = 0;
	rep(i, 1, n) if(deg[i] == 1) rt = i;
	int ss = ver[head[rt]];
	ll ans = inf;
	rep(t1, 1, 3) rep(t2, 1, 3) if(t1 != t2){
		col[rt] = t2;
		ll res = dfs(ss, rt, t1, t2) + c[t2][rt];
		//cout << res << endl;
		//rep(i, 1, n) cout << col[i] << ' '; cout << endl;
		if(res < ans) ans = res, memcpy(fc, col, sizeof(fc));
	}
	printf("%lld\n", ans);
	rep(i, 1, n) printf("%d ", fc[i]); printf("\n");
	return 0;
}
