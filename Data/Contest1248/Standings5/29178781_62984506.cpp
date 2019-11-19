#include<cstdio>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int n, a[100001];

long long solve() {
	deque<int> dq;
	for (int i = 0; i < n; ++i)
		dq.push_back(a[i]);
	sort(dq.begin(), dq.end());

	long long h = 0, w = 0;
	while (true) {
		if (dq.empty()) break;
		w += dq.back();
		dq.pop_back();
		if (dq.empty()) break;
		h += dq.front();
		dq.pop_front();
	}
	return h * h + w * w;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);

	long long ans = solve();
	printf("%I64d", ans);
}