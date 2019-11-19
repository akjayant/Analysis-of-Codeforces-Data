#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 100010;

typedef long long ll;

ll a[N];
int n;

int main()
{
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	ll xx = 0;
	for (int i = 1; i <= n / 2; i++) xx += a[i];
	ll res = xx * xx + (sum - xx) * (sum - xx);
	printf("%lld\n", res);
	return 0;
}
