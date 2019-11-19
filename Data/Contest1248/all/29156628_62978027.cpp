#include<bits/stdc++.h>

#define LL long long
#define RG register

using namespace std;
template<class T> T gi() {
	T x = 0; bool f = 0; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') f = 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f ? -x : x;
}
int a[2], b[2];
void solve() {
	int n = gi<int>();
	a[0] = a[1] = b[0] = b[1] = 0;
	for (int i = 1; i <= n; i++)
		a[gi<int>() & 1]++;
	int m = gi<int>();
	for (int i = 1; i <= m; i++)
		b[gi<int>() & 1]++;
	printf("%lld\n", 1ll * a[0] * b[0] + 1ll * a[1] * b[1]);
}
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int T = gi<int>();
	while (T--) solve();
	return 0;
}
