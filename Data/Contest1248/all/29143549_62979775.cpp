#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	long long s1 = 0, s2 = 0;
	for(int i = 1; i <= n / 2; ++i) s1 += a[i];
	for(int i = n / 2 + 1; i <= n; ++i) s2 += a[i];
	printf("%lld\n", s1 * s1 + s2 * s2);
	return 0;
}