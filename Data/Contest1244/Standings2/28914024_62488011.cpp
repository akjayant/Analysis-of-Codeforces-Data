#include <bits/stdc++.h>

using namespace std;

int d[100010];
struct edge {
	int t, nxt;
} e[200010];
int head[100010], p, c[100010][4], col[100010], root, lson, n, ansc[100010];

void add_edge(int s, int t) {
	e[++p].t = t;
	e[p].nxt = head[s]; 
	head[s] = p;
}

void dfs(int x, int fa) {
	for(int i = head[x]; i; i = e[i].nxt) {
		if(e[i].t == fa) continue ;
		if(x == root) {
			if(e[i].t != lson) col[e[i].t] = 6 - col[x] - col[lson];
		} else col[e[i].t] = 6 - col[x] - col[fa];
		dfs(e[i].t, x);
	}
}

int main() {
	cin >> n;
	int flag = 0;
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> c[j][i]; 
		}
	}
	for(int i = 1; i < n; i++) {
		int s, t;
		cin >> s >> t;
		// cout << "read : " << s << " " << t << endl;
		add_edge(s, t), add_edge(t, s);
		d[s]++, d[t]++;
		if(d[s] > 2 || d[t] > 2) flag = 1;
	}
	if(flag) {
		puts("-1");
		return 0;
	}
	if(n == 1) {
		c[1][0] = min(c[1][1], min(c[1][2], c[1][3]));
		cout << c[1][0] << endl << c[1][0] << endl;
	}
	root = 1, lson = e[head[root]].t;
	long long ans = 100000000000000000LL;
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			if(i == j) continue ;
			col[root] = i, col[lson] = j;
			dfs(1, 0);
			long long qwq = 0;
			for(int i = 1; i <= n; i++) {
				qwq += c[i][col[i]];
			}
			if(ans > qwq) {
				ans = qwq;
				for(int i = 1; i <= n; i++) ansc[i] = col[i];
			}
		}
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++) cout << ansc[i] << " ";
	return 0;
}

/*
5
3 4 2 1 2
4 2 1 5 4
5 3 2 1 1
1 2
3 2
4 3
5 3
*/