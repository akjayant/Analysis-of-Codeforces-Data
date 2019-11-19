#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		int p = 0;
		for (int i=0, x; i<n; ++i) {
			scanf("%d", &x);
			if (x&1) ++p;
		}
		int m;
		scanf("%d", &m);
		int q = 0;
		for (int i=0, x; i<m; ++i) {
			scanf("%d", &x);
			if (x&1) ++q;
		}
		printf("%lld\n", (ll)p*q + (ll)(n-p)*(m-q));
	}
	return 0;
}