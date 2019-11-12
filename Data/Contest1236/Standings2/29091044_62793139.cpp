#include <bits/stdc++.h>
using namespace std;

struct _in {
	const _in operator , (int & a) const {
		a = 0;
		char k = getchar ();
		while (k > '9' || k < '0') k = getchar ();
		while (k >= '0' && k <= '9') {
			a = a * 10 + k - '0';
			k = getchar ();
		}
		return * this;
	}
}in;

const int mod = 1e9 + 7;
inline int plu (int u, int v) { return u + v >= 0 ? u + v - mod : u + v; }
inline int sub (int u, int v) { return u - v < 0 ? u - v + mod : u - v; }
inline int mul (int u, int v) { return 1LL * u * v % mod; }
inline int fpow (int base, int v)
{
	int tot = 1;
	while (v)
	{
		if (v & 1) tot = mul (tot, base);
		base = mul (base, base);
		v >>= 1;
	}
	return tot;
}

int a[305][305];

int main () {
	int n, tot = 0;
	in, n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			a[j][i] = ++tot;
	for (int i = 2; i <= n; i += 2)
	{
		int l = 1, r = n;
		while (l < r) swap (a[l++][i], a[r--][i]);
	}
	for (int i = 1; i <= n; ++i, puts (""))
		for (int j = 1; j <= n; ++j)
			printf ("%d ", a[i][j]);
	return 0;
}
