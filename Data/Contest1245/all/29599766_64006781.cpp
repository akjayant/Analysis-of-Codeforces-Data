#include <bits/stdc++.h>

using namespace std;

pair<long long, pair<int, int> > e[4000001];
int a[10001], b[10001];
pair<int, int> ans[4000001];
int stk[10001];
int top, sz;
int n;
int f[100001];
int c[100001], k[100001];
int cnt;
int getfa(int x) { return (!f[x]) ? x : (f[x] = getfa(f[x])); }
int main( ) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &c[i]);
		e[++ cnt] = make_pair(c[i], make_pair(i, n + 1));
	}
	for (int i = 1; i <= n; i ++)
		scanf("%d", &k[i]);
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++) {
			e[++ cnt] = make_pair(1LL * (abs(a[i] - a[j]) + abs(b[i] - b[j])) * (k[i] + k[j]), make_pair(i, j));
		}
	long long tans = 0;
	sort(e + 1, e + 1 + cnt);
	for (int i = 1; i <= cnt; i ++) {
		int x = e[i].second.first;
		int y = e[i].second.second;
		int tx = getfa(x), ty = getfa(y);
		if (tx == ty) continue;
		f[tx] = ty;
		tans += e[i].first;
		if (x == n + 1) stk[++ top] = y;
		else if (y == n + 1) stk[++ top] = x;
		else {
			ans[++ sz] = make_pair(x, y);
		}
	}
	cout << tans << endl;
	printf("%d\n", top);
	for (int i = 1; i <= top; i ++)
		printf("%d ", stk[i]);
	puts("");
	printf("%d\n", sz);
	for (int i = 1; i <= sz; i ++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}
