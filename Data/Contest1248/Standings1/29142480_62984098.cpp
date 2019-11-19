#include <bits/stdc++.h>
#define rep(i, a, b) for(int i(a), i##_ORZ(b); i <= i##_ORZ; i++)
#define drep(i, a, b) for(int i(a), i##_ORZ(b); i >= i##_ORZ; i--)
using namespace std;
const int maxn = 100010;
int n, a[maxn];
int main() {
	scanf("%d", &n);
	long long s = 0, s1 = 0;
	rep(i, 1, n) scanf("%d", &a[i]), s += a[i];
	sort(a + 1, a + 1 + n);
	rep(i, 1, n / 2) s1 += a[i];
	printf("%lld\n", 1ll * s1 * s1 + 1ll * (s - s1) * (s - s1));
	return 0;
}
