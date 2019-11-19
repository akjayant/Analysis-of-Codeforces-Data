#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	int T, n,x, m;
	for (scanf("%d", &T); T--;) {
		int q1 = 0, q2 = 0, o1 = 0, o2 = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &x);
			if (x & 1) q1++;
			else o1++;
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &x);
			if (x & 1) q2++;
			else o2++;
		}
		long long ans = 1LL * q1 * q2 + 1LL * o1 * o2;
		printf("%lld\n", ans);

	}
}