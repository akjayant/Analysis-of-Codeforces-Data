#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll n, p, w, d;
	scanf("%I64d%I64d%I64d%I64d", &n, &p, &w, &d);
	ll r = w-d;
	ll tr = 0;
	for (int i=0 ; i<10000005 ; i++) {
		if (tr>p) {
			printf("-1\n");
			return 0;
		}
		if ((p-tr)%w == 0 and (p-tr)/w+i<=n) break;
		tr+=d;
		if (i == 10000004) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%I64d %I64d %I64d\n", (p-tr)/w, tr/d, n-(p-tr)/w-tr/d);
	return 0;
}