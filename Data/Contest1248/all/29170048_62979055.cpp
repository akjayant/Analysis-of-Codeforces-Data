#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int odd1 = 0, even1 = 0, odd2 = 0, even2 = 0, n, m;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int a;
			scanf("%d", &a);
			if (0 == a % 2) even1++;
			else odd1++;
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			int a;
			scanf("%d", &a);
			if (0 == a % 2) even2++;
			else odd2++;
		}
		ll res = (ll)odd1 * odd2 + (ll)even1 * even2;
		printf("%lld\n", res);
	}
	return 0;
}
