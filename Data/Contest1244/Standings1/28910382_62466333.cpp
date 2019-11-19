#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double db;

# define pi pair<int, int>
# define pb push_back

template <typename t> void Max(t &a, t b) { if(a < b) a = b; }
template <typename t> void Min(t &a, t b) { if(a > b) a = b; }
template <typename t>
inline void read(t &x) {
	x = 0; t f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar())
		if(c == '-') f = -1;
	for(;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	x *= f;
}

const int N = 0;

int cas, n;
int a, b, c, d, k;

int main() {
	for(cin >> cas; cas--; ) {
		read(a), read(b), read(c), read(d), read(k);
		int l = ceil(1.0 * a / c);
		int r = ceil(1.0 * b / d);
		if(l + r <= k) {
			printf("%d %d\n", l, r);
		} else puts("-1");
	}
	return 0;
}
