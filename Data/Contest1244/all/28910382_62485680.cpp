#pragma GCC optimize("2,Ofast,inline")
#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int, int>
using namespace std;
const int N = 1e5 + 10;

template <typename T> T read(T &x) {
	int f = 0;
	register char c = getchar();
	while (c > '9' || c < '0') f |= (c == '-'), c = getchar();
	for (x = 0; c >= '0' && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + (c ^ 48);
	if (f) x = -x;
	return x;
}

int n, m;
LL k, a[N], b[N], c[N];
map<LL, int> Map;


int main() {
	read(n); read(k);
	for (int i = 1; i <= n; ++i) read(a[i]), ++Map[a[i]];
	sort(a + 1, a + n + 1);

	a[0] = -1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] != a[i - 1]) {
			++m;
			b[m] = a[i];
			c[m] = Map[b[m]];
		}
	}

	// for (int i = 1; i <= m; ++i) {
	// 	cout << b[i] << ' ' << c[i] << endl;
	// }
	
	int L = 1, R = m;
	while (L < R) {
		if (c[L] < c[R]) {
			LL tmp = c[L] * (b[L + 1] - b[L]);
			if (tmp <= k) {
				k -= tmp;
				++L;
				c[L] += c[L - 1];
			}
			else {
				b[L] += k / c[L];
				cout << b[R] - b[L] << endl;
				return 0;
			}
		}
		else {
			LL tmp = c[R] * (b[R] - b[R - 1]);
			if (tmp <= k) {
				k -= tmp;
				--R;
				c[R] += c[R + 1];
			}
			else {
				b[R] -= k / c[R];
				cout << b[R] - b[L] << endl;
				return 0;
			}
		}
	}
	puts("0");
	return 0;
}
