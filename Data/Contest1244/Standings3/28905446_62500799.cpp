#include <bits/stdc++.h>
#define rep(i, a, b) for(int i(a), i##_ORZ(b); i <= i##_ORZ; i++)
#define drep(i, a, b) for(int i(a), i##_ORZ(b); i >= i##_ORZ; i--)
using namespace std;
const int maxn = 400010;
int n, a[maxn], K, v[maxn], pre[maxn], nxt[maxn];
char str[maxn];
int main() {
	scanf("%d%d", &n, &K);
	scanf("%s", str + 1);
	rep(i, 1, n) a[i] = (str[i] == 'B' ? 1 : 0), a[i + n] = a[i];
	a[0] = a[n], a[n + n + 1] = a[1];
	rep(i, 1, n + n) 
		if(a[i] != a[i + 1] && a[i] != a[i - 1]) v[i] = 1;
	pre[0] = 0; nxt[n + n] = n + n + 1;
	rep(i, 1, n + n) if(v[i]) pre[i] = pre[i-1]; else pre[i] = i; 
	drep(i, n + n, 1) if(v[i]) nxt[i] = nxt[i+1]; else nxt[i] = i;
	rep(i, 1, n) if(v[i]) {
		int l = pre[i + n], r = nxt[i], d, t;
		if(i + n - l < r - i) t = l, d = i + n - l;
		else t = r, d = r - i;
		if(d <= K && l != 0 && r != n + n + 1) a[i] = a[t];
		else a[i] = (a[i] + K) % 2;
	}
	rep(i, 1, n) if(a[i]) putchar('B'); else putchar('W');
	printf("\n");
	return 0;
}
