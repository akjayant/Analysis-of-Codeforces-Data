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

int main () {
	
	int t;
	in, t;
	while (t--)
	{
		int a, b, c;
		in, a, b, c;
		int k = c >> 1;
		if (b <= k) printf ("%d\n", 3 * b);
		else{
			b -= k;
			int ans = k * 3;
			k = b >> 1;
			if (a <= k) ans += 3 * a;
			else ans += 3 * k;
			printf ("%d\n", ans);
		}
	}
	return 0;
}
