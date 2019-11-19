#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;

typedef long long ll;
int n;
ll a[100000];

int main() {
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%lld", a+i);
	sort(a, a+n);
	ll p = accumulate(a, a+n/2, 0ll);
	ll q = accumulate(a+n/2, a+n, 0ll);
	printf("%lld\n", p*p+q*q);
	return 0;
}