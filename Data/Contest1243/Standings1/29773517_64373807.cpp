#include <bits/stdc++.h>

#define F(i, a, b) for (int i = a; i <= b; i ++)
#define G(i, a, b) for (int i = a; i >= b; i --)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define mx(a, b) ((a) = max(a, b))
#define mn(a, b) ((a) = min(a, b))
#define mem(a, b) memset(a, b, sizeof a)
#define mec(a, b) memcpy(a, b, sizeof a)
#define pf printf
#define sf scanf

using namespace std;

const int N = 1e3 + 10;
int k, n, a[N];

int main() {
	for (sf("%d", &k); k --; ) {
		sf("%d", &n);
		F(i, 1, n) sf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		int Ans = 0;
		F(i, 1, n)
			mx(Ans, min(n - i + 1, a[i]));
		pf("%d\n", Ans);
	}
}