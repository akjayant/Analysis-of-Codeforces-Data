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

int qp(int x, int n) {
	int ans = 1;
	while (n) {
		if (n & 1) ans = 1LL * ans * x % mod;
		x = 1LL * x * x % mod;
		n >>= 1;
	}
	return ans;
}

int main() {
	int n = read(), m = read();
	printf("%d\n", qp((qp(2, m) + mod - 1) % mod, n));
	return 0;
}
