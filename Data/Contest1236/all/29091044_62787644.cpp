#include <cstdio>
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

int main () {
	int n, m;
	scanf ("%d%d", &n, &m);
	int per = fpow (2, m) - 1;
	printf ("%d\n", fpow (per, n));
	return 0;
}
