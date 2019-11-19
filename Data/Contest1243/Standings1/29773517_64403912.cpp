#include <bits/stdc++.h>

#define F(i, a, b) for (LL i = a; i <= b; i ++)
#define G(i, a, b) for (LL i = a; i >= b; i --)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define mx(a, b) ((a) = max(a, b))
#define mn(a, b) ((a) = min(a, b))
#define mem(a, b) memset(a, b, sizeof a)
#define mec(a, b) memcpy(a, b, sizeof a)
#define pf printf
#define sf scanf

using namespace std;

typedef long long LL;

const LL N = 1e6 + 10;
LL n, z[N], Ans, L, bz[N];
LL d[N];

int main() {
	sf("%lld", &n);
	if (n == 1) {
		puts("1");
		return 0;
	}

	F(i, 2, N - 10) {
		if (!bz[i])
			z[++ z[0]] = i;
		F(j, 1, z[0]) {
			LL t = z[j] * i;
			if (t > N - 10) break;
			bz[t] = 1;
			if (i % z[j] == 0) break;
		}
	}

	LL cnt = 0, Ans = 0;
	F(i, 1, z[0]) {
		if (n > 1 && (n % z[i] == 0)) ++ cnt;
		if (cnt > 1) {
			puts("1");
			return 0;
		}
		while (n % z[i] == 0)
			n /= z[i], Ans = z[i];
	}

	if (n > 1)
		cnt ++, Ans = n;
	if (cnt > 1) {
		puts("1");
		return 0;
	}
	pf("%lld\n", Ans);
}