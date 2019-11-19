#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 210000;
int a[maxn], n, m;
long long solve() {
	map<int, int> d;
	for (int i = 1; i <= n; ++i)
		d[i] = 1;
	int offset = 0;
	for (int i = 1; i <= m; ++i) {
		auto iter = d.find(a[i] - 1 - offset);
		if (iter != d.end()) {
			auto pr = *iter;
			d.erase(iter);
			d[pr.first - 1] += pr.second;
		}
		offset += 1;
	}
	long long ans = 0;
	for (auto pr : d) {
		long long t = min(pr.first + offset + 1, n);
		ans += t * pr.second;
	}
	/*for (auto pr : d) {
		printf("%d %d\n", pr.first + offset, pr.second);
	}*/
	return ans - (long long)n * (n - 1) / 2;
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &a[i]);
	if (n == 1 && m > 0) {
		puts("0");
		return 0;
	}
	long long ans1 = solve();
	for (int i = 1; i <= m; ++i)
		a[i] = n - a[i] + 1;
	long long ans2 = solve();
	printf("%lld\n", ans1 + ans2 - n);
	return 0;
}