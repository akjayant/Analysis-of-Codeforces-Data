#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, p[100000], q[100000];

long long solve() {
	long long ep = 0, op = 0, eq = 0, oq = 0;
	for (int i = 0; i < n; ++i) {
		if (p[i] % 2) op++;
		else ep++;
	}
	for (int i = 0; i < m; ++i) {
		if (q[i] % 2) oq++;
		else eq++;
	}
	return ep * eq + op * oq;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", p + i);
		scanf("%d", &m);
		for (int i = 0; i < m; ++i)
			scanf("%d", q + i);

		long long ans = solve();
		printf("%I64d\n", ans);
	}
}