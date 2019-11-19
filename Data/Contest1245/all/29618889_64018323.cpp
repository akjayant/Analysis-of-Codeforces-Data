#include <bits/stdc++.h>

using namespace std;

struct edge {
	int s, t;
	long long v;
} e[4004010];

bool cmp(edge a, edge b) {
	return a.v < b.v;
}

int n, fa[2010], c[2010], k[2010], x[2010], y[2010], m, qwq[2010], es[4004010], et[4004010]; 

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
	cin >> n;
	for(int i = 1; i <= n + 1; i++) fa[i] = i;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) cin >> k[i];
	for(int i = 1; i <= n; i++) {
		e[i].s = 0;
		e[i].t = i;
		e[i].v = c[i];
	}
	m = n;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			long long tmp = (abs(x[i] - x[j]) + abs(y[i] - y[j]) + 0LL) * (k[i] + k[j] + 0LL);
			if(tmp <= 1000000000) {
				m++;
				e[m].s = i;
				e[m].t = j;
				e[m].v = tmp;
			}
		}
	}
	sort(e + 1, e + m + 1, cmp);
	int V = 0, E = 0;
	long long ans = 0, qwqwq = 0;
	for(int i = 1; i <= m; i++) {
		int x = find(e[i].s), y = find(e[i].t);
		if(x == y) continue ;
		qwqwq++;
		ans += e[i].v;
		if(e[i].s) E++, es[E] = e[i].s, et[E] = e[i].t;
		else V++, qwq[V] = e[i].t;
		fa[x] = y;
		if(qwqwq == n) break;
	}
	cout << ans << endl;
	cout << V << endl;
	for(int i = 1; i <= V; i++) cout << qwq[i] << " ";
	cout << endl << E << endl;
	for(int i = 1; i <= E; i++) {
		cout << es[i] << " " << et[i] << endl;
	}
	return 0;
}