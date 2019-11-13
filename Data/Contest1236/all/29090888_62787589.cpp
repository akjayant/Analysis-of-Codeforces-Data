#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int main() {
	int t = read();
	while (t --) {
	int a = read(), b = read(), c = read();
	int ans = 0;
	rep(i, 101) rep(j, 101) {
		if (i <= a && i * 2 + j <= b && j * 2 <= c) ans = max(ans, i + i * 2 + j + j * 2);
	}
	printf("%d\n", ans);
	}
	return 0;
}
