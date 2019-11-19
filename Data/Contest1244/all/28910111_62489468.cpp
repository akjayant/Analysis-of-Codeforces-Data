#include <bits/stdc++.h>
#define LL  	long long
#define Maxn	500500
using namespace std;
template <typename tn> void read(tn &a){
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

vector <int> son[Maxn];
int c[5][Maxn], deg[Maxn], a[Maxn], id[Maxn], ans[Maxn];
int n, tim;

LL calc(){
	LL ret = 0;
	for (int i = 3; i <= n; i++){
		for (int j = 1; j <= 3; j++){
			if (j == a[i - 1] || j == a[i - 2]) continue;
			a[i] = j, ret += c[j][id[i]], ans[id[i]] = j;
		}
	}
	return ret;
}

void add(int u, int v){ son[u].push_back(v), deg[v]++; }
void dfs(int u, int fa){
	id[++tim] = u;
	for (auto v : son[u]) if (v != fa) dfs(v, u);
}

int main(){
	read(n);
	for (int i = 1; i <= n; i++)
		read(c[1][i]);
	for (int i = 1; i <= n; i++)
		read(c[2][i]);
	for (int i = 1; i <= n; i++)
		read(c[3][i]);
	for (int i = 1; i < n; i++){
		int u, v; read(u), read(v);
		add(u, v), add(v, u);
	}
	int rt;
	for (int i = 1; i <= n; i++){
		if (deg[i] == 1) rt = i;
		if (deg[i] > 2){ cout << "-1\n"; return 0; }
	}
	dfs(rt, 0);
	LL Ans = 1e18, c1 = 1, c2 = 2;
	for (int i = 1; i <= 3; i++)
	for (int j = 1; j <= 3; j++){
		if (i == j) continue;
		a[1] = i, a[2] = j;
		LL t = calc() + c[i][id[1]] + c[j][id[2]];
		if (Ans > t) Ans = t, c1 = i, c2 = j;
	}
	ans[id[1]] = c1, ans[id[2]] = c2;
	a[1] = c1, a[2] = c2, calc();
	cout << Ans << '\n';
	for (int i = 1; i <= n; i++)
		cout << ans[i] << (i == n ? '\n' : ' ');
	return 0;
}
