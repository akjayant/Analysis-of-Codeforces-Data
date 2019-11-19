#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

struct node {
	int x, y;
}a[N], b[N];
int n, m, k, l, r, u, d, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
ll wt, sum;
bool cmpx(const node &x, const node &y) {
	return x.x == y.x ? x.y < y.y : x.x < y.x;
}
bool cmpy(const node &x, const node &y) {
	return x.y == y.y ? x.x < y.x : x.y < y.y;
}
bool Ask(int x, int y, int t, node &ret) {
	if(t % 2 == 0) {
		int pos = int(lower_bound(a + 1, a + 1 + k, (node){x, y}, cmpx) - a);
		if(t == 2)
			--pos;
		if(a[pos].x == x)
			return ret = a[pos], true;
	}else {
		int pos = int(lower_bound(b + 1, b + 1 + k, (node){x, y}, cmpy) - b);
		if(t == 3)
			--pos;
		if(b[pos].y == y)
			return ret = b[pos], true;
	}
	return false;
}
bool Check(int x, int y) {
	if(x <= u || x >= d || y <= l || y >= r)
		return true;
	int pos = int(lower_bound(a + 1, a + 1 + k, (node){x, y}, cmpx) - a);
	return a[pos].x == x && a[pos].y == y;
}
int main() {
	//freopen("D.in", "r", stdin);
	scanf("%d%d%d", &n, &m, &k), wt = 1ll * n * m - k;
	l = u = 0, r = m + 1, d = n + 1;
	for(int i = 1; i <= k; ++i)
		scanf("%d%d", &a[i].x, &a[i].y), b[i] = a[i];
	sort(a + 1, a + 1 + k, cmpx);
	sort(b + 1, b + 1 + k, cmpy);
	sum = 1;
	for(int x = 1, y = 1, tx, ty, t = 0; ; ) {
		//printf("%d %d\n", x, y);
		node p;
		tx = x, ty = y;
		if(Ask(x, y, t, p)) {
			if(t == 0)
				ty = min(p.y, r) - 1;
			else if(t == 1)
				tx = min(p.x, d) - 1;
			else if(t == 2)
				ty = max(p.y, l) + 1;
			else
				tx = max(p.x, u) + 1;
		}else {
			if(t == 0)
				ty = r - 1;
			else if(t == 1)
				tx = d - 1;
			else if(t == 2)
				ty = l + 1;
			else
				tx = u + 1;
		}
		sum += abs(tx - x) + abs(ty - y);
		x = tx, y = ty;
		(++t) %= 4;
		if(Check(x + dx[t], y + dy[t]))
			break;
		if(t == 1)
			u = x;
		else if(t == 2)
			r = y;
		else if(t == 3)
			d = x;
		else
			l = y;
	}
	puts(sum == wt ? "Yes" : "No");
	return 0;
}

